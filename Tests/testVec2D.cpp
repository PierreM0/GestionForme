//
// Created by pierrem on 07/12/23.
//

#include <gtest/gtest.h>

#include "../Vecteur2D.h"

TEST(testVec2D, testAdd)
{
    Vecteur2D vec = Vecteur2D(1, 1);
    ASSERT_EQ(Vecteur2D(2, 2), vec + vec);
}
TEST(testVec2D, testAddAssign)
{

    Vecteur2D v1 = Vecteur2D(1, 1);
    Vecteur2D v2 = Vecteur2D(2, 2);
    v1 += v2;
    ASSERT_EQ(v1, Vecteur2D(3, 3));

    v1 = Vecteur2D(1, 1);
    Vecteur2D v3 = v1 += v2;
    ASSERT_EQ(v1, Vecteur2D(3, 3));
    ASSERT_EQ(v3, v1);
}

TEST(testVec2D, testMin)
{
    const auto v1 = Vecteur2D(1, 1);
    const auto v2 = -v1;
    ASSERT_EQ(v2, Vecteur2D(-1, -1));
    ASSERT_EQ(v2 - v2, Vecteur2D(0, 0));
}

TEST(testVec2D, testMult)
{
    const auto v1 = Vecteur2D(1, 1);
    const auto v2 = Vecteur2D(2, 2);
    ASSERT_EQ(2 * v1, v2);
    ASSERT_EQ(v1 * 2, v2);
    ASSERT_EQ(v1 * v2, 4);
}

TEST (testVec2D, testNorme)
{
    const auto v1 = Vecteur2D(1, 0);
    ASSERT_EQ(v1.norme(), 1);
}

// TestMult
// nestNorme