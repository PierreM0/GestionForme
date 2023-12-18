//
// Created by pierrem on 07/12/23.
//

#ifndef VECTEUR2D_H
#define VECTEUR2D_H

//
// Created by pierrem on 06/12/23.
//

#include <cmath>
#include <sstream>
#include <string>

using namespace std;

class Vecteur2D {
public:
  double x, y;

  Vecteur2D() : x(0), y(0) {}
  Vecteur2D(const double &x, const double &y) : x(x), y(y) {}

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

  double normeCarree() const { return *this * *this; }

  double norme() const { return sqrt(normeCarree()); }

  bool operator==(const Vecteur2D &v) const { return x == v.x && y == v.y; }

  double determinant(const Vecteur2D &v) const { return x * v.y - y * v.x; }
};

inline ostream &operator<<(ostream &o, const Vecteur2D &v) {
  return o << string(v);
}

inline Vecteur2D operator*(const double &d, const Vecteur2D &v) {
  return v * d;
}

#endif // VECTEUR2D_H
