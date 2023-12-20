#ifndef INTERSECTION_FORME_COR_H
#define INTERSECTION_FORME_COR_H

#include "IntersectionForme.h"

class IntersectionFormeCor : public IntersectionForme {
  IntersectionFormeCor *suivant = nullptr;

public:
  IntersectionFormeCor(IntersectionFormeCor *ifc) : suivant(ifc) {}

  bool se_croisent(const Forme &f1, const Forme &f2) const override {
    bool res = se_croisent1(f1, f2);
    if (res)
      return true;

    if (suivant == nullptr)
      return false;
    return suivant->se_croisent(f1, f2);
  }

  virtual bool se_croisent1(const Forme &f1, const Forme &f2) const = 0;
};

#endif // !INTERSECTION_FORME_COR_H
