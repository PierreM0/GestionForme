//
// Created by thomas on 10/02/24.
//

#ifndef GESTIONFORME_ANALYSEURTXTTRIANGLE_H
#define GESTIONFORME_ANALYSEURTXTTRIANGLE_H

#include <iostream>
#include <fstream>
#include <cstring>
#include "AnalyseurTxtCOR.h"
#include "../../Formes/FormeSimple/Triangle.h"
#include "../../Geometrie/Point2D.h"

class AnalyseurTxtTriangle : public AnalyseurTxtCOR {
public:
    AnalyseurTxtTriangle(AnalyseurTxt *suiv) : AnalyseurTxtCOR(suiv) {}

    Forme * analyser1(std::ifstream &is) const override {
        string line;
        streampos oldpos = is.tellg(); // Sauvegarde de la position actuelle dans le fichier
        if (!getline(is, line)) {
            is.seekg(oldpos); // Retour à la ligne précédente
            return nullptr;
        }
        if (line != "triangle") {
            is.seekg(oldpos); // Retour à la ligne précédente
            return nullptr;
        }
        string couleur;
        getline(is, couleur);
        double x1, y1, x2, y2, x3, y3;
        getline(is, line);
        sscanf(line.c_str(), "%lf %lf", &x1, &y1);
        getline(is, line);
        sscanf(line.c_str(), "%lf %lf", &x2, &y2);
        getline(is, line);
        sscanf(line.c_str(), "%lf %lf", &x3, &y3);
        auto *triangle = new Triangle(Forme::Couleur(strdup(couleur.c_str())), Point2D(x1, y1), Point2D(x2, y2), Point2D(x3, y3));
        return triangle;
    }
};

#endif //GESTIONFORME_ANALYSEURTXTTRIANGLE_H
