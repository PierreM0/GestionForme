//
// Created by thomas on 18/12/23.
//

#ifndef PROJET_INTERFACEGRAPHIQUE_H
#define PROJET_INTERFACEGRAPHIQUE_H

#include "../Geometrie/Point2D.h"

class Segment;
class Polygone;
class Triangle;
class Cercle;

/**
 * Cette classe représente une interface graphique capable de dessiner des
 * formes.
 */
class InterfaceGraphique {
public:
  /**
   * Dessine un segment.
   * @param forme : le segment
   */
  virtual void dessiner(const Segment &forme) const = 0;

  /**
   * Dessine un polygone.
   * @param forme : le polygone
   */
  virtual void dessiner(const Polygone &forme) const = 0;

  /**
   * Dessine un cercle.
   * @param forme : le cercle
   */
  virtual void dessiner(const Cercle &forme) const = 0;

  /**
   * Dessine un triangle.
   * @param forme : le triangle
   */
  virtual void dessiner(const Triangle &forme) const = 0;

  /**
   * Nettoie la zone de dessin.
   */
  virtual void nettoyer() const = 0;

  /**
   * Définit la zone du monde en donnant les 2 points d'une diagonale de cette
   * zone.
   * @param p1 : le 1er point
   * @param p2 : le 2ème point
   */
  virtual void definirZoneMonde(const Point2D &p1, const Point2D &p2) const = 0;
};

#endif // PROJET_INTERFACEGRAPHIQUE_H
