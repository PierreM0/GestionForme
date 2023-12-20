//
// Created by pierrem on 16/12/23.
//

#ifndef GROUPE_H
#define GROUPE_H
#include <memory>
#include <vector>

#include "../InterfacesGraphiques/InterfaceGraphique.h"
#include "ExceptionForme.h"
#include "Forme.h"
#include "Intersection/IntersectionCercleCercle.h"
#include "Intersection/IntersectionSegmentCercle.h"
#include "Intersection/IntersectionSegmentSegment.h"

class Groupe : public Forme {

  /// Only one forme of each.
  vector<unique_ptr<Forme>> formes;

public:
  explicit Groupe(const Couleur &color) : Forme(color) {}

  void add(const unique_ptr<Forme> &f) {

    IntersectionFormeCor *inter_forme = new IntersectionSegmentSegment(nullptr);
    inter_forme = new IntersectionSegmentCercle(inter_forme);
    inter_forme = new IntersectionCercleCercle(inter_forme);

    for (auto &forme : formes) {
      if (inter_forme->se_croisent(*forme, *f))
        throw ExceptionForme(ExceptionForme::AJOUT_IMPOSSIBLE);
    }

    formes.push_back(f);
  }

  void translation(const Vecteur2D &translation) override {
    for (auto &f : formes) {
      f->translation(translation);
    }
  }
  void homotetie(const Point2D &point_invariant,
                 const double &rapport) override {
    for (auto &f : formes) {
      f->homotetie(point_invariant, rapport);
    }
  }
  void rotation(const Point2D &point_invariant, const double &theta) override {
    for (auto &f : formes) {
      f->rotation(point_invariant, theta);
    }
  }

  bool operator==(const Forme &f) const override {
    const Groupe *g;
    if ((g = dynamic_cast<const Groupe *>(&f)) == nullptr)
      return false;
    for (auto &forme : formes) {
      bool found = false;
      for (const auto &gforme : g->formes)
        if (*forme == *gforme) {
          found = true;
          break;
        }
      if (!found)
        return false;
    }

    return true;
  }

  operator string() const override {
    ostringstream s;
    s << "Groupe: " << endl;
    for (auto &forme : formes) {
      s << "    " << string(*forme) << endl;
    }
    return s.str();
  }

  double aire() const override {
    double aire = 0;
    for (auto &f : formes) {
      aire += f->aire();
    }
    return aire;
  }

  void dessiner(const InterfaceGraphique &ig) const override {
    for (auto &f : formes) {
      f->dessiner(ig);
    }
  }
};

#endif //! GROUPE_H
