#include "../../../Formes/FormeSimple/Triangle.h"
#include <gtest/gtest.h>
#include <valarray>
#include <cmath>

TEST(testCercle, testTranslation)
{
    Forme* f = new Triangle(Forme::Couleur::RED, Point2D(0, 0), Point2D(1, 1), Point2D(0, 1));
    const Forme* f2 = new Triangle(Forme::Couleur::RED, Point2D(1, 0), Point2D(2, 1), Point2D(1, 1));
    f->translation(Vecteur2D(1, 0));

    ASSERT_EQ(*f, *f2);
}

TEST(testCercle, testHomotetie)
{
    Forme* f = new Triangle(Forme::Couleur::RED, Point2D(0, 0), Point2D(1, 1), Point2D(0, 1));
    const Forme* f2 = new Triangle(Forme::Couleur::RED, Point2D(0, 0), Point2D(2, 2), Point2D(0, 2));
    f->homotetie(Point2D(0, 0), 2.0);

    ASSERT_EQ(*f, *f2);
}

TEST(testCercle, testRotation)
{
    auto t = Triangle(Forme::Couleur::RED, Point2D(0, 0), Point2D(1, 1), Point2D(0, 1));
    const auto t2 = Triangle(Forme::Couleur::RED, Point2D(0, 0), Point2D(-1, 0), Point2D(-1, -1));
    t.rotation(Point2D(0, 0), M_PI_2l);

    ASSERT_NEAR(t.a.x, t2.a.x, 1e-15);
    ASSERT_NEAR(t.a.y, t2.a.y, 1e-15);
    ASSERT_NEAR(t.b.y, t2.b.x, 1e-15);
    ASSERT_NEAR(t.b.y, t2.b.y, 1e-15);
    ASSERT_NEAR(t.c.x, t2.c.x, 1e-15);
    ASSERT_NEAR(t.c.y, t2.c.y, 1e-15);
}
