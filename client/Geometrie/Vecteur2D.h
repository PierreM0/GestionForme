//
// Created by pierrem on 07/12/23.
//

#ifndef VECTEUR2D_H
#define VECTEUR2D_H

#include <cmath>
#include <sstream>
#include <string>

using namespace std;

/**
 * Classe représentant un vecteur à 2 dimensions
 */
class Vecteur2D {
public:
  double x, y;

  /**
   * Crée un vecteur par défaut (x = 0, y = 0)
   */
  Vecteur2D() : x(0), y(0) {}

  /**
   * Crée un vecteur à partir de ses deux composantes
   * @param x
   * @param y
   */
  Vecteur2D(const double &x, const double &y) : x(x), y(y) {}

  /**
   * Crée un vecteur unitaire à partir d'un angle
   * @param alpha l'angle en radians
   * @return le vecteur unitaire
   */
  static const Vecteur2D creeVecteurUnitaire(const double &alpha) {
    return Vecteur2D(cos(alpha), sin(alpha));
  }

  explicit operator string() const {
    ostringstream o;
    o << "(" << x << ", " << y << ")";
    return o.str();
  }

  Vecteur2D operator+(const Vecteur2D &v) const {
    return Vecteur2D{x + v.x, y + v.y};
  }

  const Vecteur2D &operator+=(const Vecteur2D &v) {
    x += v.x;
    y += v.y;
    return *this;
  }

  Vecteur2D operator-() const { return Vecteur2D{-x, -y}; }

  Vecteur2D operator-(const Vecteur2D &v) const {
    return Vecteur2D{x - v.x, y - v.y};
  }

  Vecteur2D operator*(const double &d) const { return Vecteur2D{d * x, d * y}; }
  Vecteur2D operator/(const double &d) const { return *this * (1 / d); }

  double operator*(const Vecteur2D &v) const { return x * v.x + y * v.y; }

  /**
   * Calcule la norme au carré du vecteur
   * @return la norme au carré
   */
  double normeCarree() const { return *this * *this; }

  /**
   * Calcule la norme du vecteur
   * @return la norme
   */
  double norme() const { return sqrt(normeCarree()); }

  bool operator==(const Vecteur2D &v) const { return x == v.x && y == v.y; }

  /**
   * Calcule le déterminant entre ce vecteur et un autre vecteur donné
   * @param v l'autre vecteur
   * @return le déterminant
   */
  double determinant(const Vecteur2D &v) const { return x * v.y - y * v.x; }
};

inline ostream &operator<<(ostream &o, const Vecteur2D &v) {
  return o << string(v);
}

inline Vecteur2D operator*(const double &d, const Vecteur2D &v) {
  return v * d;
}

#endif // VECTEUR2D_H
