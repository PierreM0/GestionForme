#ifndef INTERSECTION_CERCLE_CERCLE_H
#define INTERSECTION_CERCLE_CERCLE_H
#include "../../Geometrie/GeometriePlane.h"
#include "../FormeSimple/Cercle.h"
#include "IntersectionFormeCOR.h"

class IntersectionCercleCercle : public IntersectionFormeCor {
public:
  IntersectionCercleCercle(IntersectionFormeCor *ifc)
      : IntersectionFormeCor(ifc) {}

  bool se_croisent1(const Forme &f1, const Forme &f2) const override {
    const Cercle *c1;
    if ((c1 = dynamic_cast<const Cercle *>(&f1)) == nullptr)
      return false;
    const Cercle *c2;
    if ((c2 = dynamic_cast<const Cercle *>(&f2)) == nullptr)
      return false;

    return GeometriePlane::inter_cercle_cercle(c1->c, c1->rayon, c2->c,
                                               c2->rayon);
  }
};
#endif //! INTERSECTION_CERCLE_CERCLE_H
