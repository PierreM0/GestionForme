#ifndef INTERSECTION_FORME_H
#define INTERSECTION_FORME_H

#include "../Forme.h"
class IntersectionForme {
  virtual bool se_croisent(const Forme &f1, const Forme &f2) const = 0;
};

#endif // !INTERSECTION_FORME_H
