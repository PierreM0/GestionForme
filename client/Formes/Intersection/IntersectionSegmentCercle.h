#ifndef INTERSECTION_SEGMENT_CERCLE_H
#define INTERSECTION_SEGMENT_CERCLE_H

#include "../FormeSegmentee.h"
#include "../FormeSimple/Cercle.h"
#include "../FormeSimple/Segment.h"
#include "IntersectionFormeCOR.h"

class IntersectionSegmentCercle : public IntersectionFormeCor {
public:
  IntersectionSegmentCercle(IntersectionFormeCor *ifc)
      : IntersectionFormeCor(ifc) {}

  bool se_croisent1(const Forme &f1, const Forme &f2) const override {
    const FormeSegmentee *fs;
    const Cercle *c1;
    if ((fs = dynamic_cast<const FormeSegmentee *>(&f1)) == nullptr) {
      if ((fs = dynamic_cast<const FormeSegmentee *>(&f2)) == nullptr) {
        return false;
      }
      if ((c1 = dynamic_cast<const Cercle *>(&f1)) == nullptr) {
        return false;
      }
    }
    if ((c1 = dynamic_cast<const Cercle *>(&f2)) == nullptr) {
      return false;
    }

    for (Segment s : fs->get_all_segments()) {
      if (GeometriePlane::inter_cercle_segment(c1->c, c1->rayon, s.a, s.b))
        return true;
    }

    return false;
  }
};

#endif // !INTERSECTION_SEGMENT_CERCLE_H
