#include "../../Geometrie/GeometriePlane.h"
#include "../../Geometrie/Vecteur2D.h"
#include <gtest/gtest.h>

TEST(testGeoPlan, equation2inconnue) {
  Vecteur2D a(5, -2), b(4, 9), c(7, -24), res1(3, -2);
  auto res = GeometriePlane::resolution_systeme_22(a, b, c);
  ASSERT_EQ(res, res1);
}

TEST(testGeoPlan, inter_droite_droite) {
  Vecteur2D i(3.25, -1.75);
  Vecteur2D p0(-6.5, -4);
  Vecteur2D q0(7, 5);

  Vecteur2D p0p1 = 3 * (i - p0);
  Vecteur2D q0q1 = -4.5 * (i - q0);

  auto p1 = p0 + p0p1;
  auto q1 = q0 + q0q1;

  auto i1 = GeometriePlane::inter_droite_droite(p0, p1, q0, q1);
}
TEST(testGeoPlan, interCercleDroite) {
  Vecteur2D i1(3, 0), i2(5, 0), c(4, 9);
  double rayon = (i2 - c).norme();

  Vecteur2D p0(11, 0), p1(-3, 0);

  auto res = GeometriePlane::inter_cercle_droite(c, rayon, p0, p1);

  ASSERT_FLOAT_EQ(res.first.x, i2.x);
  ASSERT_FLOAT_EQ(res.first.y, i2.y);
  ASSERT_FLOAT_EQ(res.second.x, i1.x);
  ASSERT_FLOAT_EQ(res.second.y, i1.y);
}

TEST(testGeoPlan, interCercleCercle) {
  Vecteur2D c(0, 0), c1(2, 0), c2(10, 10);

  ASSERT_EQ(GeometriePlane::inter_cercle_cercle(c, 4, c1, 4), true);
  ASSERT_EQ(GeometriePlane::inter_cercle_cercle(c, 4, c2, 4), false);
}
