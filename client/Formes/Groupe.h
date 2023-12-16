#ifndef FORME_COMPOSEE_H
#define FORME_COMPOSEE_H

#include "Formes.h"
#include <memory>
#include <vector>
class Groupe : public Forme {
  /// Pointeur unique vers une forme, la forme est virtuelle, et il ne peux y
  /// avoir qu'une instance par forme
  vector<unique_ptr<Forme>> formes;

public:
  /// Cree une FormeComposee vide.
  /// @param color le couleur de la forme.
  Groupe(Color color) : Forme(color) {}

  /// Ajoutes une forme dans la forme composée.
  /// @param forme: la forme a ajouter
  Groupe &add(const unique_ptr<Forme> &forme) {
    // TODO:
    // for (const auto &f : formes) {
    //  if (f->join(forme))
    //    throw FormeException(FormeException::INTERSECTION_DU_GROUPE);
    // }
    formes.push_back(forme);
    return *this;
  }

  void translation(const Vecteur2D &translation) override {
    for (const auto &forme : formes) {
      forme->translation(translation);
    }
  }

  void homotetie(const Point2D &point_invariant,
                 const double &rapport) override {
    for (const auto &forme : formes) {
      forme->homotetie(point_invariant, rapport);
    }
  }

  void rotation(const Point2D &point_invariant, const double &theta) override {
    for (const auto &forme : formes) {
      forme->rotation(point_invariant, theta);
    }
  }

  bool operator==(const Groupe &f) {
    if (this == &f) return true;
    for (int i = 0; i < formes.size(); ++i)
    {
      if (f->formes[i] != formes[i]) return false;
    }
    return true;
  }
};

#endif // !FORME_COMPOSEE_H
