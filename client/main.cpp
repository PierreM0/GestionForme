#include "Formes/Forme.h"
#include "Formes/FormeSimple/Polygone.h"
#include "Formes/FormeSimple/Segment.h"
#include "Formes/FormeSimple/Triangle.h"
#include "InterfacesGraphiques/ClientTCP/ClientTCP.h"
#include <memory>

int main(int argc, char *argv[]) {
  ClientTcp client = ClientTcp("127.0.0.1", 12345);
  // client.nettoyer();
  client.definirZoneMonde(Point2D(-20, -20), Point2D(20, 20));

  Segment s = Segment(Forme::Couleur::RED, Point2D(0, 0), Point2D(-10, 7));
  Polygone p = Polygone(Forme::Couleur::BLUE)
                   .add(Point2D(8, 6))
                   .add(Point2D(-14, 7))
                   .add(Point2D(-4, 12))
                   .add(Point2D(11, 14));

  Triangle t = Triangle(Forme::Couleur::BLACK, Point2D(-19, -4),
                        Point2D(-6, -6), Point2D(-4, -19));

  Cercle c = Cercle(Forme::Couleur::GREEN, Point2D(-6, 6), 6);

  s.dessiner(client);
  p.dessiner(client);
  t.dessiner(client);
  c.dessiner(client);

  return 0;
}
