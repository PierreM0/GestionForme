//
// Created by thomas on 16/01/24.
//

#ifndef GESTIONFORME_ANALYSEURTXTSEGMENT_H
#define GESTIONFORME_ANALYSEURTXTSEGMENT_H

#include <iostream>
#include <fstream>
#include <cstring>
#include "AnalyseurTxtCOR.h"
#include "../../Formes/FormeSimple/Segment.h"
#include "../../Geometrie/Point2D.h"

class AnalyseurTxtSegment : public AnalyseurTxtCOR {
public:
    AnalyseurTxtSegment(AnalyseurTxt *suiv) : AnalyseurTxtCOR(suiv) {}

    Forme * analyser1(std::ifstream &is) const override {
        string line;
        streampos oldpos = is.tellg(); // Sauvegarde de la position actuelle dans le fichier
        if (!getline(is, line)) {
            is.seekg(oldpos); // Retour à la ligne précédente
            return nullptr;
        }
        if (line != "segment") {
            is.seekg(oldpos); // Retour à la ligne précédente
            return nullptr;
        }
        string couleur;
        getline(is, couleur);
        double x1, y1, x2, y2;
        getline(is, line);
        sscanf(line.c_str(), "%lf %lf", &x1, &y1);
        getline(is, line);
        sscanf(line.c_str(), "%lf %lf", &x2, &y2);
        auto *segment = new Segment(Forme::Couleur(strdup(couleur.c_str())), Point2D(x1, y1), Point2D(x2, y2));
        return segment;
    }
};

#endif //GESTIONFORME_ANALYSEURTXTSEGMENT_H
