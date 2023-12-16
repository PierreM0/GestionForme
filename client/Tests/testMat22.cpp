//
// Created by pierrem on 11/12/23.
//

#include <gtest/gtest.h>

#include "../Matrice22.h"
#include "../Vecteur2D.h"
#include <cmath>

TEST(mat22, rotation)
{
    Vecteur2D c(2, 0);
    double alpha = M_PIl/2;
    auto R = Matrice22::creeRotation(alpha);
    double theta = -M_PIl/4;
    auto u = Vecteur2D::creeVecteurUnitaire(theta);
    typedef Vecteur2D Point;
    Point p = c + 3 * u;
    Point p1 = R * (p - c) + c;
    ASSERT_FLOAT_EQ(p.y, -p1.y);
}