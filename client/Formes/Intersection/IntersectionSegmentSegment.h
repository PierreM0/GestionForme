#ifndef INTERSECTION_SEGMENT_SEGMENT_H
#define INTERSECTION_SEGMENT_SEGMENT_H
#include "../../Geometrie/GeometriePlane.h"
#include "../FormeSegmentee.h"
#include "../FormeSimple/Segment.h"
#include "IntersectionFormeCOR.h"

class IntersectionSegmentSegment : public IntersectionFormeCor {
public:
  IntersectionSegmentSegment(IntersectionFormeCor *ifc)
      : IntersectionFormeCor(ifc) {}

  bool se_croisent1(const Forme &f1, const Forme &f2) const override {
    const FormeSegmentee *fs1;
    if ((fs1 = dynamic_cast<const FormeSegmentee *>(&f1)) == nullptr)
      return false;
    const FormeSegmentee *fs2;
    if ((fs2 = dynamic_cast<const FormeSegmentee *>(&f2)) == nullptr)
      return false;

    for (Segment s1 : fs1->get_all_segments()) {
      for (Segment s2 : fs2->get_all_segments()) {
        if (GeometriePlane::inter_segment_segment(s1.a, s1.b, s2.a, s2.b))
          return true;
      }
    }

    return false;
  }
};
#endif //! INTERSECTION_SEGMENT_SEGMENT_H
