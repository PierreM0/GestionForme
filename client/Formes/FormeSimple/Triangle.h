#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "../../Geometrie/Matrice22.h"
#include "../../Geometrie/Point2D.h"
#include "../FormeSegmentee.h"
#include "Segment.h"

/**
 * Classe représentant un triangle.
 */
class Triangle : public FormeSegmentee {
public:
  Point2D a, b, c;

  /**
   * Crée un nouveau triangle à partir d'une couleur et de 3 points
   * @param couleur la couleur
   * @param a le premier point
   * @param b le deuxième point
   * @param c le troisième point
   */
  Triangle(const Couleur &couleur, const Point2D &a, const Point2D &b,
           const Point2D &c)
      : FormeSegmentee(couleur), a(a), b(b), c(c) {}

  void translation(const Vecteur2D &translation) override {
    a += translation;
    b += translation;
    c += translation;
  }

  void homotetie(const Point2D &point_invariant,
                 const double &rapport) override {
    a = (a + point_invariant) * rapport;
    b = (b + point_invariant) * rapport;
    c = (c + point_invariant) * rapport;
  }

  void rotation(const Point2D &point_invariant, const double &theta) override {
    const double ctheta = cos(theta);
    const double stheta = sin(theta);

    a = Matrice22(ctheta, -stheta, stheta, ctheta) * a + point_invariant;
    b = Matrice22(ctheta, -stheta, stheta, ctheta) * b + point_invariant;
    c = Matrice22(ctheta, -stheta, stheta, ctheta) * c + point_invariant;
  }

  bool operator==(const Forme &f) const override {
    const Triangle *t;
    if ((t = dynamic_cast<const Triangle *>(&f)) == nullptr)
      return false;
    return this->c == t->c && a == t->a && b == t->b;
  }

  explicit operator string() const override {
    ostringstream s;
    s << "Triangle [ " << a << ";" << b << ";" << c << " ]";
    return s.str();
  }

  /** https://fr.wikipedia.org/wiki/Aire_d'un_triangle#%C3%80_partir_des_coordonn%C3%A9es_des_sommets  */
  double aire() const override {
    return abs((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y)) / 2;
  }

  const vector<Segment> get_all_segments() const override {
    vector<Segment> res;
    res.push_back(Segment(Couleur::BLACK, a, b));
    res.push_back(Segment(Couleur::BLACK, a, c));
    res.push_back(Segment(Couleur::BLACK, c, b));

    return res;
  }

  void dessiner(const InterfaceGraphique &ig) const override {
    ig.dessiner(*this);
  }

    const string &sauvegarder(const SauvegardeurTxt &sauvegardeur, const string &chemin) const override {
        return sauvegardeur.sauvegarder(*this, chemin);
    }
};

#endif // !TRIANGLE_H
