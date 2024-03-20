#include "Formes/Forme.h"
#include "Formes/Groupe.h"
#include "Formes/FormeSimple/Polygone.h"
#include "Formes/FormeSimple/Segment.h"
#include "Formes/FormeSimple/Triangle.h"
#include "InterfacesGraphiques/ClientTCP/ClientTCP.h"
#include "Chargeur/ChargeurTxt.h"
#include <memory>

int main(int argc, char *argv[]) {
  ClientTcp client = ClientTcp::getClient();

  client.definirZoneMonde(Point2D(-20, -20), Point2D(20, 20));

  Polygone* R1 = new Polygone(Forme::Couleur::BLUE);
  R1->add(Point2D(1, -1));
  R1->add(Point2D(5, -1));
  R1->add(Point2D(5, 1));
  R1->add(Point2D(1, 1));
  unique_ptr<Forme> uR1 = unique_ptr<Polygone>(R1);

  Triangle* T1 = new Triangle(Forme::Couleur::GREEN, Point2D(6, -1),
                        Point2D(8, 0), Point2D(6, 1));
  unique_ptr<Forme> uT1 = unique_ptr<Triangle>(T1);


  Cercle* C1 = new Cercle(Forme::Couleur::YELLOW, Point2D(11, 0), 2);
  unique_ptr<Forme> uC1 = unique_ptr<Cercle>(C1);

  Groupe G1 = Groupe(Forme::Couleur::RED);
  G1.add(uR1);
  G1.add(uT1);
  G1.add(uC1);

  G1.translation(Vecteur2D(-1, 0));
  G1.rotation(Point2D(0, 0), M_PI_4);
  double aire = G1.aire();
  cout << "Aire : " << aire << endl;
  G1.dessiner(client);

  SauvegardeurTxt sauvegardeurTxt;
  G1.sauvegarder(sauvegardeurTxt, "mabellefigure1.txt");

  Forme *G2 = ChargeurTxt::charger("mabellefigure1.txt");

  G2->translation(Vecteur2D(4, 4));
  G2->setColor(Forme::Couleur::BLUE);

  G2->dessiner(client);

  client.fermer();

  return 0;
}
