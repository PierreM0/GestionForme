#ifndef FORME_SEGMENTEE_H
#define FORME_SEGMENTEE_H

#include "Forme.h"
#include <vector>
class Segment;

/**
 * Classe représentant une forme formée de plusieurs segments
 */
class FormeSegmentee : public Forme {
public:

  FormeSegmentee(const Couleur &c) : Forme(c) {}

  /**
   * @return les segments de la forme
   */
  virtual const vector<Segment> get_all_segments() const = 0;
};

#endif // !FORME_SEGMENTEE_H
