package app.window;

import app.geometry.Vector2D;

import java.awt.Color;

/**
 * Cette interface contient toutes les méthodes de dessin demandées dans le projet
 */
public interface Window {

    /**
     * Dessine un segment allant de p1 à p2 avec la couleur donnée
     * @param p1 Le premier point
     * @param p2 Le deuxième point
     * @param color La couleur
     */
    void drawLine(Vector2D p1, Vector2D p2, Color color);

    /**
     * Dessine un polygone de couleur donnée dont les points sont donnés en paramètres. Les points doivent être fournis
     * dans le sens horaire. Peut être plein ou vide.
     * @param points Les points
     * @param color La couleur
     * @param fill <i>true</i> si le polygone doit être plein, <i>false</i> sinon
     */
    void drawPolygon(Vector2D[] points, Color color, boolean fill);

    /**
     * Dessine un cercle de couleur, centre et rayon donnés. Peut être plein ou vide.
     * @param center Le centre
     * @param radius Le rayon
     * @param color La couleur
     * @param fill <i>true</i> si le cercle doit être plein, <i>false</i> sinon
     */
    void drawCircle(Vector2D center, double radius, Color color, boolean fill);

    /**
     * Vide entièrement la zone de dessin
     */
    void clear();

    /**
     * Met à jour la zone de dessin
     * @param zone un tableau de 2 {@link Vector2D} représentant les 2 points d'une diagonale de la zone
     */
    void updateWorldZone(Vector2D[] zone);
}
