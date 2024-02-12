#ifndef GEOMETRIE_PLANE_H
#define GEOMETRIE_PLANE_H
#include "ExceptionGeometriePlane.h"
#include "Matrice22.h"
#include "Vecteur2D.h"
#include <cmath>
#include <utility>

/**
 * Classe utilitaire réalisant différentes opérations de géometrie plane
 */
class GeometriePlane {
public:

  /**
   * Résoud le système ax + by = c. <strong>Attention à la div par zéro</strong>.
   * @param a
   * @param b
   * @param c
   * @return le couple (x, y)
   */
  static const Vecteur2D resolution_systeme_22(const Vecteur2D &a,
                                               const Vecteur2D &b,
                                               const Vecteur2D &c) {
    double det = a.determinant(b);
    if (det == 0)
      throw ExceptionGeometriePlane(ExceptionGeometriePlane::DETERMINANT_NUL);
    Vecteur2D r(c.determinant(b), a.determinant(c));
    return r / det;
  }

  /**
   * Calcule le point d'intersection I des droites (p0, p1) et (q0, q1). On calcule s et t deux nombres réels tels que
   * vec(p0, I) = s * vec(p0, p1) et vec(q0, I) = t * vec(q0, q1).
   * @param p0 le 1er point définissant la 1ère droite
   * @param p1 le 2ème point définissant la 1ère droite
   * @param q0 le 1er point définissant la 2ème droite
   * @param q1 le 2ème point définissant la 2ème droite
   * @return le point d'intersection des droites
   */
  static const Vecteur2D
  inter_droite_droite_inner_coordonees(const Vecteur2D &p0, const Vecteur2D &p1,
                                       const Vecteur2D &q0,
                                       const Vecteur2D &q1) {
    Vecteur2D p0p1 = p1 - p0;
    Vecteur2D q1q0 = q0 - q1;
    Vecteur2D p0q0 = q0 - p0;

    return resolution_systeme_22(p0p1, q1q0, p0q0);
  }

  /**
   * Calcule le point d'intersection I des droites (p0, p1) et (q0, q1). On calcule s et t deux nombres réels tels que
   * vec(p0, I) = s * vec(p0, p1) et vec(q0, I) = t * vec(q0, q1).
   * @param p0 le 1er point définissant la 1ère droite
   * @param p1 le 2ème point définissant la 1ère droite
   * @param q0 le 1er point définissant la 2ème droite
   * @param q1 le 2ème point définissant la 2ème droite
   * @return le point d'intersection des droites
   */
  static const Vecteur2D inter_droite_droite(const Vecteur2D &p0,
                                             const Vecteur2D &p1,
                                             const Vecteur2D &q0,
                                             const Vecteur2D &q1) {
    auto res = inter_droite_droite_inner_coordonees(p0, p1, q0, q1);

    Vecteur2D p0p1 = p1 - p0;
    Vecteur2D q0q1 = q1 - q0;

    Vecteur2D I1 = res.x * p0p1 + p0;
    Vecteur2D I2 = res.y * q0q1 + q0;

    return (I1 + I2) / 2;
  }

  /**
   * Vérifie si deux segments s'intersectionnent et calcule le point d'intersection.
   * @param p0 le 1er point du 1er segment
   * @param p1 le 2ème point du 1er segment
   * @param q0 le 1er point du 2ème segment
   * @param q1 le 2ème point du 2ème segment
   * @param I le point d'intersection calculé par la fonction
   * @return <i>true</i> s'ils s'intersectionnent, <i>false</i> sinon
   */
  static bool inter_segment_segment_inner_coordonees(const Vecteur2D &p0,
                                                     const Vecteur2D &p1,
                                                     const Vecteur2D &q0,
                                                     const Vecteur2D &q1,
                                                     Vecteur2D &I) {
    I = inter_droite_droite_inner_coordonees(p0, p1, q0, q1);
    return 0 <= I.y && I.y <= 1 && 0 <= I.x && I.x <= 1;
  }

  /**
   * Vérifie si deux segments s'intersectionnent.
   * @param p0 le 1er point du 1er segment
   * @param p1 le 2ème point du 1er segment
   * @param q0 le 1er point du 2ème segment
   * @param q1 le 2ème point du 2ème segment
   * @return <i>true</i> s'ils s'intersectionnent, <i>false</i> sinon
   */
  static bool inter_segment_segment(const Vecteur2D &p0, const Vecteur2D &p1,
                                    const Vecteur2D &q0, const Vecteur2D &q1) {

    Vecteur2D I;
    return inter_segment_segment_inner_coordonees(p0, p1, q0, q1, I);
  }

  /**
   * Résoud une équation du second degré
   * @param a
   * @param b
   * @param c
   * @return les 2 solutions de l'équation
   * @throws ExceptionGeometriePlane si delta < 0
   */
  static const pair<double, double>
  resoudre_equation_second_degre(const double &a, const double &b,
                                 const double &c) {
    double delta = b * b - 4 * a * c;
    if (delta <= 0)
      throw ExceptionGeometriePlane(ExceptionGeometriePlane::DELTA_NEGATIF);
    double sqrt_delta = sqrt(delta);
    auto x1 = (-b - sqrt_delta) / (2 * a);
    auto x2 = (-b + sqrt_delta) / (2 * a);

    return pair(x1, x2);
  }

  /**
   * Calcule les coordonnées d'intersection entre un cercle et une droite.
   * @param c le centre du cercle
   * @param rayon le rayon du cercle
   * @param p0 le 1er point définissant la droite
   * @param p1 le 2ème point définissant la droite
   * @return les coordonnées d'intersection
   * @throws ExceptionGeometriePlane si delta < 0
   */
  static pair<Vecteur2D, Vecteur2D> inter_cercle_droite(const Vecteur2D &c,
                                                        const double &rayon,
                                                        const Vecteur2D &p0,
                                                        const Vecteur2D &p1) {
    Vecteur2D p0p1 = p1 - p0;
    Vecteur2D cp0 = p0 - c;

    auto t = resoudre_equation_second_degre(p0p1 * p0p1, 2 * (cp0 * p0p1),
                                            cp0 * cp0 - rayon * rayon);

    pair<Vecteur2D, Vecteur2D> r;
    r.first = t.first * p0p1 + p0;
    r.second = t.second * p0p1 + p0;

    return r;
  }

  /**
   * Vérifie si un cercle et un segment d'intersectionnent.
   * @param c le centre du cercle
   * @param rayon le rayon du cercle
   * @param p0 le 1er point définissant le segment
   * @param p1 le 2ème point définissant le segment
   * @return <i>true</i> s'ils s'intersectionnent, <i>false</i> sinon
   */
  static bool inter_cercle_segment(const Vecteur2D &c, const double &rayon,
                                   const Vecteur2D &p0, const Vecteur2D &p1) {

    try {
      auto res = inter_cercle_droite(c, rayon, p0, p1);

      if (p0.x != p1.x) {
        auto aux = p0.x > p1.x ? p0 : p1;
        auto aux1 = p0.x > p1.x ? p1 : p0;
        const Vecteur2D p0 = aux;
        const Vecteur2D p1 = aux1;

        return p0.x <= res.first.x && res.first.x <= p1.x ||
               p0.x <= res.second.x && res.second.x <= p1.x;
      }
      auto auy = p0.y > p1.y ? p0 : p1;
      auto auy1 = p0.y > p1.y ? p1 : p0;
      const Vecteur2D p0_ = auy;
      const Vecteur2D p1_ = auy1;

      return p0_.y <= res.first.y && p1_.y >= res.first.y ||
             p0_.y <= res.second.y && p1_.y >= res.second.y;

    } catch (...) {
      return true;
    }
  }

  /**
   * Vérifie si deux cercles d'intersectionnent.
   * @param c1 le centre du 1er cercle
   * @param r1 le rayon du 1er cercle
   * @param c2 le centre du 2ème cercle
   * @param r2 le rayon du 2ème cercle
   * @return <i>true</i> s'ils s'intersectionnent, <i>false</i> sinon
   */
  static bool inter_cercle_cercle(const Vecteur2D &c1, const double &r1,
                                  const Vecteur2D &c2, const double &r2) {

    auto d =
        sqrt((c2.x - c1.x) * (c2.x - c1.x) + (c2.y - c1.y) * (c2.y - c1.y));

    if (d >= r1 + r2)
      return false;

    /* leur position:
     auto a = (r1 * r1 - r2 * r2 + d * d) / (2 * d);
     auto b = (r2 * r2 - r1 * r1 + d * d) / (2 * d);
     auto h = sqrt(r1 * r1 - a * a);

     Vecteur2D c1c2 = c2 - c1;

     auto centre_inter = c1 + (a / d) * (c1c2);

     auto I1 = Vecteur2D(centre_inter.x - h*(c1c2.y)/d,
     centre_inter.y + h*(c1c2.x)/d);

     auto I2 = Vecteur2D(centre_inter.x + h*(c1c2.y)/d,
     centre_inter.y - h*(c1c2.x)/d);

     */

    return true;
  }
};

#endif // !GEOMETRIE_PLANE_H
