//
// Created by thomas on 10/02/24.
//

#ifndef GESTIONFORME_ANALYSEURTXTCERCLE_H
#define GESTIONFORME_ANALYSEURTXTCERCLE_H

#include <iostream>
#include <fstream>
#include <cstring>
#include "AnalyseurTxtCOR.h"
#include "../../Formes/FormeSimple/Cercle.h"
#include "../../Geometrie/Point2D.h"

class AnalyseurTxtCercle : public AnalyseurTxtCOR {
public:
    AnalyseurTxtCercle(AnalyseurTxt *suiv) : AnalyseurTxtCOR(suiv) {}

    Forme * analyser1(std::ifstream &is) const override {
        string line;
        streampos oldpos = is.tellg(); // Sauvegarde de la position actuelle dans le fichier
        if (!getline(is, line)) {
            is.seekg(oldpos); // Retour à la ligne précédente
            return nullptr;
        }
        if (line != "cercle") {
            is.seekg(oldpos); // Retour à la ligne précédente
            return nullptr;
        }
        string couleur;
        getline(is, couleur);
        double x, y;
        getline(is, line);
        sscanf(line.c_str(), "%lf %lf", &x, &y);
        double radius;
        getline(is, line);
        sscanf(line.c_str(), "%lf", &radius);
        auto *cercle = new Cercle(Forme::Couleur(strdup(couleur.c_str())), Point2D(x, y), radius);
        return cercle;
    }
};

#endif //GESTIONFORME_ANALYSEURTXTCERCLE_H
