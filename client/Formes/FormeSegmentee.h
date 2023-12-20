#ifndef FORME_SEGMENTEE_H
#define FORME_SEGMENTEE_H

#include "Forme.h"
#include <vector>
class Segment;

class FormeSegmentee : public Forme {
public:
  /**
   * @brief retourne tous les segments de la forme. sous forme d'un vecteur de
   * segments.
   */
  virtual const vector<Segment> get_all_segments() const = 0;
  FormeSegmentee(const Couleur &c) : Forme(c) {}
};

#endif // !FORME_SEGMENTEE_H
