#include <gtest/gtest.h>
#include <valarray>
#include <cmath>

#include "../../../Formes/FormeSimple/Polygone.h"

TEST(testPolygone, testTranslation)
{
    auto f = Polygone(Forme::Couleur::RED);
    f.add(Point2D(0, 0)).add(Point2D(1, 2)).add( Point2D(2, 0)).add( Point2D(1, 1));

    auto f2 = Polygone(Forme::Couleur::RED);
    f2.add(Point2D(1, 0)).add(Point2D(2, 2)).add( Point2D(3, 0)).add( Point2D(2, 1));

    f.translation(Vecteur2D(1, 0));


    ASSERT_EQ(f, f2);
}

TEST(testPolygone, testHomotetie)
{
    auto f = Polygone(Forme::Couleur::RED);
    f.add(Point2D(0, 0)).add(Point2D(1, 2)).add( Point2D(2, 0)).add( Point2D(1, 1));

    auto f2 = Polygone(Forme::Couleur::RED);
    f2.add(Point2D(0, 0)).add(Point2D(2, 4)).add( Point2D(4, 0)).add( Point2D(2, 2));

    f.homotetie(Point2D(0, 0), 2.0);

    ASSERT_EQ(f, f2);
}

TEST(testPolygone, testRotation)
{
    auto f = Polygone(Forme::Couleur::RED);
    f.add(Point2D(0, 0)).add(Point2D(1, 2)).add( Point2D(2, 0)).add( Point2D(1, 1));

    auto f2 = Polygone(Forme::Couleur::RED);
    f2.add(Point2D(0, 0)).add(Point2D(-2, 1)).add( Point2D(0, 2)).add( Point2D(-1, 1));

    f2.rotation(Point2D(0, 0), M_PI_2l);

    for(int i = 0; i < f.points.size(); ++i) {
        ASSERT_NEAR(f.points[i].x, f2.points[i].x, 1e-15);
        ASSERT_NEAR(f.points[i].y, f2.points[i].y, 1e-15);
    }
}
