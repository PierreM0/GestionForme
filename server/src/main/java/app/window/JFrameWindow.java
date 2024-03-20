package app.window;

import app.geometry.Vector2D;

import javax.swing.JFrame;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.image.BufferStrategy;
import java.util.function.Consumer;

/**
 * Implémentation de l'interface Window avec la classe {@link JFrame} de AWT
 */
public class JFrameWindow extends JFrame implements Window {

    private static final String TITLE = "GestionForme";
    private static final Dimension DEFAULT_DIMENSION = new Dimension(720, 480);

    private final BufferStrategy bStrategy;
    private Vector2D[] worldZone; // = Rect
    private Vector2D scaleVector = new Vector2D(); // = lambda
    private Vector2D offset = new Vector2D(); // = omega

    public JFrameWindow() {
        this.setTitle(TITLE); // Titre de la fenêtre
        this.setSize(DEFAULT_DIMENSION); // Taille initiale de la fenêtre
        this.setLocationRelativeTo(null); // Apparition de la fenêtre au centre de l'ecran
        this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE); // Termine le processus à la fermeture de la fenêtre
        this.setIgnoreRepaint(true); // Ignore le repaint pour l'active rendering
        this.setVisible(true);
        this.createBufferStrategy(2); // Initialise le double-buffering pour l'active rendering
        try {
            Thread.sleep(200); // Pause pour laisser le temps de créer les buffers (pas sûr que ce soit utile)
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        this.bStrategy = this.getBufferStrategy();
    }

    @Override
    public void drawLine(Vector2D p1, Vector2D p2, Color color) {
        Vector2D viewportP1 = worldToViewport(p1);
        Vector2D viewportP2 = worldToViewport(p2);
        useBufferGraphics(g -> {
            g.setColor(color);
            g.drawLine((int) viewportP1.getX(), (int) viewportP1.getY(), (int) viewportP2.getX(), (int) viewportP2.getY());
        });
    }

    @Override
    public void drawPolygon(Vector2D[] points, Color color, boolean fill) {
        int[] xPoints = new int[points.length];
        int[] yPoints = new int[points.length];
        for (int i = 0; i < points.length; i++) {
            Vector2D viewportPoint = worldToViewport(points[i]);
            xPoints[i] = (int) viewportPoint.getX();
            yPoints[i] = (int) viewportPoint.getY();
        }
        useBufferGraphics(g -> {
            g.setColor(color);
            if (fill) {
                g.fillPolygon(xPoints, yPoints, points.length);
            } else {
                g.drawPolygon(xPoints, yPoints, points.length);
            }
            g.drawLine(0, 0, 5, 5);
        });

    }

    @Override
    public void drawCircle(Vector2D center, double radius, Color color, boolean fill) {
        Vector2D startPoint = worldToViewport(new Vector2D(center.getX() - radius, center.getY() + radius));
        Vector2D endPoint = worldToViewport(new Vector2D(center.getX() + radius, center.getY() - radius));
        int length = (int) (endPoint.getX() - startPoint.getX());
        useBufferGraphics(g -> {
            g.setColor(color);
            if (fill) {
                g.fillOval((int) startPoint.getX(), (int) startPoint.getY(), length, length);
            } else {
                g.drawOval((int) startPoint.getX(), (int) startPoint.getY(), length, length);
            }
        });
    }

    @Override
    public void clear() {
        Vector2D[] worldZoneToViewportZone = new Vector2D[] { worldToViewport(worldZone[0]), worldToViewport(worldZone[1]) };
        int width = (int) Math.abs(worldZoneToViewportZone[1].getX() - worldZoneToViewportZone[0].getX());
        int height = (int) Math.abs(worldZoneToViewportZone[1].getY() - worldZoneToViewportZone[0].getY());
        useBufferGraphics(g -> {
//            g.clearRect(
//                    (int) Math.min(worldZoneToViewportZone[0].getX(), worldZoneToViewportZone[1].getX()),
//                    (int) Math.min(worldZoneToViewportZone[0].getY(), worldZoneToViewportZone[1].getY()),
//                    width,
//                    height
//            );
        });
    }

    @Override
    public void updateWorldZone(Vector2D[] zone) {
        this.worldZone = zone;
        updateScale();
    }

    /**
     * Met à jour les valeurs utiles au passage coordonnées monde à écran. Cette méthode est appelée après un
     * redimensionnement de la zone monde ou de la fenêtre
     */
    private void updateScale() {
        if (worldZone == null) throw new IllegalStateException("world zone is not defined");
        // Calcul de lambda
        double scaleFactor = Math.min(
                this.getWidth() / Math.abs(worldZone[1].getX() - worldZone[0].getX()),
                this.getHeight() / Math.abs(worldZone[1].getY() - worldZone[0].getY())
        );
        this.scaleVector = new Vector2D(scaleFactor, -scaleFactor);
        // Calcul de omega
        Vector2D viewportCenter = new Vector2D(this.getWidth() / 2d, this.getHeight() / 2d);
        Vector2D worldZoneCenter = new Vector2D(
                (worldZone[0].getX() + worldZone[1].getX()) / 2d,
                (worldZone[0].getY() + worldZone[1].getY()) / 2d
        );
        this.offset = viewportCenter.add(worldZoneCenter.scalarMult(-scaleFactor));
    }

    /**
     * Effectue le passage d'un point du monde à l'écran
     * @param point le point
     * @return le point passé en coordonnées écran
     */
    private Vector2D worldToViewport(Vector2D point) {
        return point.copy().vectorMult(scaleVector).add(offset);
    }

    /**
     * Met à disposition un objet {@link Graphics} puis affiche le buffer courant et supprime l'objet après que le
     * traitement soit terminé
     * @param consumer le traitement à effectuer sur l'objet {@link Graphics}
     */
    private void useBufferGraphics(Consumer<Graphics> consumer) {
        Graphics g = bStrategy.getDrawGraphics();
        consumer.accept(g);
        bStrategy.show();
        g.dispose();
    }
}
