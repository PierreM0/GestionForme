//
// Created by pierrem on 11/12/23.
//

#ifndef MATRICE22_H
#define MATRICE22_H
#include "Vecteur2D.h"

/**
 * Cette classe représente une matrice carré 2*2
 */
class Matrice22
{
public:
    Vecteur2D haut, bas;

    /**
     * Crée une matrice identité
     */
    Matrice22(): haut(Vecteur2D(1, 0)), bas(Vecteur2D(0, 1))
    {
    };

    /**
     * Crée une matrice à partir de ses lignes
     * @param haut la ligne du haut
     * @param bas la ligne du bas
     */
    explicit Matrice22(const Vecteur2D& haut, const Vecteur2D& bas): haut(haut), bas(bas)
    {
    }

    /**
     * Crée une matrice en donnat ses quatre composantes
     * @param a première composante (ligne 1, colonne 1)
     * @param b deuxième composante (ligne 1, colonne 2)
     * @param c troisième composante (ligne 2, colonne 1)
     * @param d quatrième composante (ligne 2, colonne 2)
     */
    explicit Matrice22(const double& a, const double& b, const double& c, const double& d):
        haut(Vecteur2D(a, b)), bas(Vecteur2D(c, d))
    {
    }

    /**
     * Crée une matrice de rotation à partir d'un angle
     * @param alpha l'angle en radians
     * @return la matrice de rotation
     */
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
