#include "../../../Formes/FormeSimple/Segment.h"
#include <gtest/gtest.h>
#include <valarray>
#include <cmath>

#include "../../../Formes/FormeSimple/Cercle.h"

TEST(testCercle, testTranslation)
{
    // Cercle Trigonométrique UwU
    Forme* f = new Cercle(Forme::Couleur::RED, Point2D(0, 0), 1);
    const Forme* f2 = new Cercle(Forme::Couleur::RED, Point2D(1, 0), 1);
    f->translation(Vecteur2D(1, 0));

    ASSERT_EQ(*f, *f2);
}

TEST(testCercle, testHomotetie)
{
    Forme* f = new Cercle(Forme::Couleur::RED, Point2D(1, 0), 1);
    const Forme* f2 = new Cercle(Forme::Couleur::RED, Point2D(2, 0), 2);
    f->homotetie(Point2D(0, 0), 2.0);
    cout << string(*f) << string(*f2);
    ASSERT_EQ(*f, *f2);
}

TEST(testCercle, testRotation)
{
    Cercle s = Cercle(Forme::Couleur::RED, Point2D(1, 0), 1);
    Cercle s2 = Cercle(Forme::Couleur::RED, Point2D(0, 1), 1);
    s.rotation(Point2D(0, 0), M_PIl / 2);

    ASSERT_NEAR(s.c.x, s2.c.x, 1e-15);
    ASSERT_NEAR(s.c.y, s2.c.y, 1e-15);
    ASSERT_NEAR(s.rayon, s2.rayon, 1e-15);
}
