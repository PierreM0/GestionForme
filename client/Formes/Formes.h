#ifndef FORMES_H
#define FORMES_H

#include "../Point2D.h"
#include "../Vecteur2D.h"

class Forme {
public:
  /// Couleurs disponibles
  enum Color {
    BLACK,
    BLUE,
    RED,
    GREEN,
    YELLOW,
    CYAN,
  };

private:
  Color color;

protected:
  bool dans_un_groupe;

public:
  /// Une forme est définie par une couleur
  Forme(Color color) : color(color), dans_un_groupe(false){};

  /// La translation est une operation de décalage dans le plan. Elle s'applique
  /// sur l'objet implicite.
  /// @param translation Le vecteur de translation
  virtual void translation(const Vecteur2D &translation) = 0;

  /// L'homotetie est une operation de zoom. Elle s'applique sur l'objet
  /// implicite.
  /// @param point_invariant le point sur lequel va se baser l'homotetie
  /// @param rapport le rapport d'homothetie, il va définir le zoom ou le
  /// dézoom.
  virtual void homotetie(const Point2D &point_invariant, const double &rapport);

  /// La rotation s'applique sur l'objet implicite.
  /// @param point_invariant le point sur lequel va se baser la rotation
  /// @param point_invariant l'angle sur lequel va se baser la rotation
  virtual void rotation(const Point2D &point_invariant, const double &theta);
};

#endif // !FORMES_H