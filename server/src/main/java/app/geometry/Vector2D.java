package app.geometry;

/**
 * Une classe représentant un vecteur à 2 dimensions avec des operations basiques
 */
public class Vector2D {

    private double x, y;

    /**
     * Crée un vecteur en donnant ses 2 composantes
     * @param x
     * @param y
     */
    public Vector2D(double x, double y) {
        this.x = x;
        this.y = y;
    }

    /**
     * Constructeur par défaut (x = 0, y = 0)
     */
    public Vector2D() {
        this.x = 0;
        this.y = 0;
    }

    /**
     * Fais la somme de ce vecteur et du vecteur v passé en paramètre
     * @param v l'autre vecteur
     * @return ce vecteur après l'opération
     */
    public Vector2D add(Vector2D v) {
        this.x += v.x;
        this.y += v.y;
        return this;
    }

    /**
     * Multiplie les composantes de ce vecteur par un réel
     * @param s le réel
     * @return ce vecteur après l'opération
     */
    public Vector2D scalarMult(double s) {
        this.x *= s;
        this.y *= s;
        return this;
    }

    /**
     * Fais le produit des composantes de ce vecteur et du vecteur v passé en paramètre
     * @param v l'autre vecteur
     * @return ce vecteur après l'opération
     */
    public Vector2D vectorMult(Vector2D v) {
        this.x *= v.x;
        this.y *= v.y;
        return this;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    /**
     * Fais une copie profonde de ce vecteur
     * @return la copie du vecteur
     */
    public Vector2D copy() {
        return new Vector2D(x, y);
    }

    @Override
    public String toString() {
        return "(" + x + ", " + y + ")";
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == this) return true;
        if (!(obj instanceof Vector2D v)) return false;
        return x == v.x && y == v.y;
    }
}
