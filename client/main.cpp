#include "Formes/Forme.h"
#include "Formes/Groupe.h"
#include "Formes/FormeSimple/Polygone.h"
#include "Formes/FormeSimple/Segment.h"
#include "Formes/FormeSimple/Triangle.h"
#include "InterfacesGraphiques/ClientTCP/ClientTCP.h"
#include "Chargeur/ChargeurTxt.h"
#include <memory>

int main(int argc, char *argv[]) {
  // Test sauvegarde / chargement
//  unique_ptr<Forme> uniqueS = std::make_unique<Segment>(Forme::Couleur::RED, Point2D(0, -10), Point2D(1, -10));
//  Polygone* p1 = new Polygone(Forme::Couleur::GREEN);
//  p1->add(Point2D(-2, -2));
//  p1->add(Point2D(2, -2));
//  p1->add(Point2D(2, 2));
//  p1->add(Point2D(-2, 2));
//  unique_ptr<Forme> uniqueP = unique_ptr<Polygone>(p1);
//  unique_ptr<Forme> uniqueT = std::make_unique<Triangle>(Forme::Couleur::YELLOW, Point2D(-20, 0), Point2D(-20, 4), Point2D(-18, 4));
//  unique_ptr<Forme> uniqueC = make_unique<Cercle>(Forme::Couleur::CYAN, Point2D(15, 15), 2);
//  Groupe g1 = Groupe(Forme::Couleur::BLUE);
//  g1.add(uniqueS);
//  g1.add(uniqueP);
//  g1.add(uniqueT);
//  g1.add(uniqueC);
//
//  SauvegardeurTxt sauvegardeurTxt;
//  g1.sauvegarder(sauvegardeurTxt, "groupe.txt");
//
//  Forme *forme = ChargeurTxt::charger("groupe.txt");
//  forme->sauvegarder(sauvegardeurTxt, "groupe2.txt");

  ClientTcp client = ClientTcp::getClient();
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

  client.fermer();

  return 0;
}
