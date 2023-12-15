//
// Created by pierrem on 11/12/23.
//

#ifndef MATRICE22_H
#define MATRICE22_H
#include "Vecteur2D.h"

class Matrice22
{
public:
    Vecteur2D haut, bas;

    Matrice22(): haut(Vecteur2D(1, 0)), bas(Vecteur2D(0, 1))
    {
    };

    explicit Matrice22(const Vecteur2D& haut, const Vecteur2D& bas): haut(haut), bas(bas)
    {
    }

    explicit Matrice22(const double& a, const double& b, const double& c, const double& d):
        haut(Vecteur2D(a, b)), bas(Vecteur2D(c, d))
    {
    }

    /// @brief joue le role d'un constructeur
    /// cos(alpha) -sin(alpha)
    /// sin(apha)  cos(alpha)
    /// @... alpha
    /// @return Matrice22
    static Matrice22 creeRotation(const double& alpha)
    {
        double calpha = cos(alpha);
        double salpha = sin(alpha);
        return Matrice22(calpha, -salpha, salpha, calpha);
    }

    Vecteur2D operator*(const Vecteur2D &v) const
    {
        return Vecteur2D(haut*v, bas*v);
    }
};
#endif //MATRICE22_H
