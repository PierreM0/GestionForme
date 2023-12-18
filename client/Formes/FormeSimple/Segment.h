#ifndef SEGMENT_H
#define SEGMENT_H

#include "../../Geometrie/Matrice22.h"
#include "../../Geometrie/Point2D.h"
#include "../Forme.h"
#include <cmath>

class Segment : public Forme {
public:
  Point2D a, b;
  /// Un segment est définit par 2 points
  Segment(const Couleur &color, const Point2D &a, const Point2D &b)
      : Forme(color), a(a), b(b) {}

  void translation(const Vecteur2D &translation) override {
    a += translation;
    b += translation;
  }

  void homotetie(const Point2D &point_invariant,
                 const double &rapport) override {
    a = Vecteur2D(a.x - point_invariant.x, a.y - point_invariant.y) * rapport;
    b = Vecteur2D(b.x - point_invariant.x, b.y - point_invariant.y) * rapport;
  }

  void rotation(const Point2D &point_invariant, const double &theta) override {
    const double ctheta = cos(theta);
    const double stheta = sin(theta);

    a = Matrice22(ctheta, -stheta, stheta, ctheta) * a + point_invariant;
    b = Matrice22(ctheta, -stheta, stheta, ctheta) * b + point_invariant;
  }

  bool operator==(const Forme &f) const override {
    const Segment *s;
    if ((s = dynamic_cast<const Segment *>(&f)) == nullptr)
      return false;
    return s->a == a && s->b == b;
  }

  explicit operator string() const override {
    ostringstream s;
    s << "Segment [ " << a << ";" << b << " ]";
    return s.str();
  }

  double aire() const override { return 0; }

  void dessiner(const InterfaceGraphique &ig) const {
    ig.dessiner(*this);
  }
};

#endif // !SEGMENT_H
