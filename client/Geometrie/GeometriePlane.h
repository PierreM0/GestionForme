#ifndef GEOMETRIE_PLANE_H
#define GEOMETRIE_PLANE_H
#include "ExceptionGeometriePlane.h"
#include "Matrice22.h"
#include "Vecteur2D.h"
#include <cmath>
#include <utility>

class GeometriePlane {
public:
  /**
   * resoud le systeme ax + by = c
   * retourne le couple (x, y)
   * ATTENTION DIV PAR ZERO
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

  /// calcule le point d'intersection I des droite (p0, p1) et (q0, q1)
  /// on calcule s et t 2 nombres réels tel que vec(p0, I) = s*vec(p0, p1)
  /// et vec(q0, I) = t*vec(q0, q1)
  /// retourne (s, t)
  static const Vecteur2D
  inter_droite_droite_inner_coordonees(const Vecteur2D &p0, const Vecteur2D &p1,
                                       const Vecteur2D &q0,
                                       const Vecteur2D &q1) {
    Vecteur2D p0p1 = p1 - p0;
    Vecteur2D q1q0 = q0 - q1;
    Vecteur2D p0q0 = q0 - p0;

    return resolution_systeme_22(p0p1, q1q0, p0q0);
  }

  /// calcule le point d'intersection I des droite (p0, p1) et (q0, q1)
  /// on calcule s et t 2 nombres réels tel que vec(p0, I) = s*vec(p0, p1)
  /// et vec(q0, I) = t*vec(q0, q1)
  /// retourne I
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

  /// retourne I le point d'intersection
  /// retourne si deux segment s'intersectionent.
  static bool inter_segment_segment_inner_coordonees(const Vecteur2D &p0,
                                                     const Vecteur2D &p1,
                                                     const Vecteur2D &q0,
                                                     const Vecteur2D &q1,
                                                     Vecteur2D &I) {
    I = inter_droite_droite_inner_coordonees(p0, p1, q0, q1);
    return 0 <= I.y && I.y <= 1 && 0 <= I.x && I.x <= 1;
  }

  /// retourne si deux segment s'intersectionent.
  static bool inter_segment_segment(const Vecteur2D &p0, const Vecteur2D &p1,
                                    const Vecteur2D &q0, const Vecteur2D &q1) {

    Vecteur2D I;
    return inter_segment_segment_inner_coordonees(p0, p1, q0, q1, I);
  }

  /// prend 3 vecteurs, et retournes les 2 vec
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

  /// retournes le couple de coordonnées d'intersection. throw une erreur, si
  /// delta < 0.
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
