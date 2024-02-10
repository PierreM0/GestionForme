//
// Created by thomas on 10/02/24.
//

#ifndef GESTIONFORME_ANALYSEURTXTPOLYGONE_H
#define GESTIONFORME_ANALYSEURTXTPOLYGONE_H

#include <iostream>
#include <fstream>
#include <cstring>
#include "AnalyseurTxtCOR.h"
#include "../../Formes/FormeSimple/Polygone.h"
#include "../../Geometrie/Point2D.h"

class AnalyseurTxtPolygone : public AnalyseurTxtCOR {
public:
    AnalyseurTxtPolygone(AnalyseurTxt *suiv) : AnalyseurTxtCOR(suiv) {}

    Forme * analyser1(std::ifstream &is) const override {
        string line;
        streampos oldpos = is.tellg(); // Sauvegarde de la position actuelle dans le fichier
        if (!getline(is, line)) {
            is.seekg(oldpos); // Retour à la ligne précédente
            return nullptr;
        }
        if (line != "polygone") {
            is.seekg(oldpos); // Retour à la ligne précédente
            return nullptr;
        }
        string couleur;
        getline(is, couleur);
        int nPoints;
        getline(is, line);
        sscanf(line.c_str(), "%d", &nPoints);
        auto *polygone = new Polygone(Forme::Couleur(strdup(couleur.c_str())));
        for (int i = 0; i < nPoints; i++) {
            double x, y;
            getline(is, line);
            sscanf(line.c_str(), "%lf %lf", &x, &y);
            polygone->add(Point2D(x, y));
        }
        return polygone;
    }
};

#endif //GESTIONFORME_ANALYSEURTXTPOLYGONE_H
