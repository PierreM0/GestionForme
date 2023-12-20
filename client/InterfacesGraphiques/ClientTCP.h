#ifndef CLIENT_TCP_H
#define CLIENT_TCP_H

#include "InterfaceGraphique.h"
class ClientTcp : public InterfaceGraphique {
  void dessiner(const Segment &forme) const override;
  void dessiner(const Polygone &forme) const override;
  void dessiner(const Cercle &forme) const override;
  void dessiner(const Triangle &forme) const override;
  void nettoyer() const override;
  void definirZoneMonde(const Point2D &p1, const Point2D &p2) const override;
};

#endif // !CLIENT_TCP_H
