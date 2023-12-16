#include "../../../Formes/FormeSimple/Segment.h"
#include <gtest/gtest.h>
#include <valarray>
#include <cmath>

TEST(testSeg, testTranslation)
{
    Segment s = Segment(Forme::Couleur::RED, Point2D(0, 0), Point2D(0, 1));
    Segment s2 = Segment(Forme::Couleur::RED, Point2D(1, 0), Point2D(1, 1));
    s.translation(Vecteur2D(1, 0));

    ASSERT_EQ(s, s2);
}

TEST(testSeg, testHomotetie)
{
    {
        Segment s = Segment(Forme::Couleur::RED, Point2D(1, 0), Point2D(1, 1));
        Segment s2 = Segment(Forme::Couleur::RED, Point2D(2, 0), Point2D(2, 2));
        s.homotetie(Point2D(0, 0), 2.0);

        ASSERT_EQ(s, s2);
    }
    {
        Segment s = Segment(Forme::Couleur::RED, Point2D(23, -2), Point2D(-31, 17));
        Segment s2 = Segment(Forme::Couleur::RED, Point2D(11.5, -1), Point2D(-15.5, 8.5));
        s.homotetie(Point2D(0, 0), 0.5);

        ASSERT_EQ(s, s2);
    }
}

TEST(testSeg, testRotation)
{
    Segment s = Segment(Forme::Couleur::RED, Point2D(0, 0), Point2D(1, 0));
    Segment s2 = Segment(Forme::Couleur::RED, Point2D(0, 0), Point2D(0, 1));
    s.rotation(Point2D(0, 0), M_PIl / 2);

    ASSERT_NEAR(s.a.x, s2.a.x, 1e-15);
    ASSERT_NEAR(s.b.x, s2.b.x, 1e-15);
    ASSERT_NEAR(s.a.y, s2.a.y, 1e-15);
    ASSERT_NEAR(s.b.y, s2.b.y, 1e-15);
}
