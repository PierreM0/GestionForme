#ifndef POLYGONE_H
#define POLYGONE_H
#include <vector>

#include "../../Matrice22.h"
#include "../../Point2D.h"
#include "../Forme.h"

class Polygone : public Forme {
public:
  vector<Point2D> points;

  /// The polygon needs to be at least a triangle
  explicit Polygone(const Couleur &couleur) : Forme(couleur) {}

  Polygone &add(const Point2D &p) {
    points.push_back(p);
    return *this;
  }

  void translation(const Vecteur2D &translation) override {
    for (auto &point : points)
      point += translation;
  }

  void homotetie(const Point2D &point_invariant,
                 const double &rapport) override {
    for (auto &point : points) {
      point = (point + point_invariant) * rapport;
    }
  }

  void rotation(const Point2D &point_invariant, const double &theta) override {
    const double ctheta = cos(theta);
    const double stheta = sin(theta);

    for (auto &point : points) {
      point =
          Matrice22(ctheta, stheta, -stheta, ctheta) * point + point_invariant;
    }
  }

  bool operator==(const Forme &f) const override {
    const Polygone *p;
    if ((p = dynamic_cast<const Polygone *>(&f)) == nullptr)
      return false;
    for (auto point : points) {
      bool found = false;
      for (const auto ppoint : p->points)
        if (point == ppoint) {
          found = true;
          break;
        }
      if (!found)
        return false;
    }
    return true;
  }

  explicit operator string() const override {
    ostringstream s;
    s << "Polygone [ ";
    for (const auto p : points) {
      s << p << "; ";
    }
    s << "] ";

    return s.str();
  }

  double aire() const override {
    double aire = 0.0;

    for (int i = 0; i < points.size() - 1; ++i) {
      aire +=
          (points[i + 1].x + points[i].x) * (points[i + 1].y - points[i].y) / 2;
    }
    return aire;
  }
};

#endif // !POLYGONE_H
