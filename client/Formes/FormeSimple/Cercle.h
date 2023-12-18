#ifndef CERCLE_H
#define CERCLE_H
#include "../../Matrice22.h"
#include "../../Point2D.h"
#include "../Forme.h"
#include <cmath>

class Cercle : public Forme {
public:
  Point2D c;
  double rayon;

  Cercle(const Couleur &couleur, const Point2D &c, const double &rayon)
      : Forme(couleur), c(c), rayon(rayon) {}

  void translation(const Vecteur2D &translation) override { c += translation; }

  void homotetie(const Point2D &point_invariant,
                 const double &rapport) override {
    rayon *= rapport;
    c = (c + point_invariant) * rapport;
  }

  void rotation(const Point2D &point_invariant, const double &theta) override {
    const double ctheta = cos(theta);
    const double stheta = sin(theta);

    c = Matrice22(ctheta, -stheta, stheta, ctheta) * c + point_invariant;
  }

  bool operator==(const Forme &f) const override {
    const Cercle *c;
    if ((c = dynamic_cast<const Cercle *>(&f)) == nullptr)
      return false;
    return this->c == c->c && rayon == c->rayon;
  }

  explicit operator string() const override {
    ostringstream s;
    s << "Cercle ( " << c << ";" << rayon << " )";
    return s.str();
  }

  double aire() const override { return M_PIl * rayon * rayon; }

  void dessiner(const InterfaceGraphique &ig) const {
    ig.dessiner(*this);
  }
};

#endif // !CERCLE_H
