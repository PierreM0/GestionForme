//
// Created by thomas on 10/02/24.
//

#ifndef GESTIONFORME_ANALYSEURTXTGROUPE_H
#define GESTIONFORME_ANALYSEURTXTGROUPE_H

#include <iostream>
#include <fstream>
#include <cstring>
#include "AnalyseurTxtCOR.h"
#include "../../Formes/Groupe.h"
#include "../../Geometrie/Point2D.h"
#include "../ChargeurTxt.h"

class AnalyseurTxtGroupe : public AnalyseurTxtCOR {
public:
    AnalyseurTxtGroupe(AnalyseurTxt *suiv) : AnalyseurTxtCOR(suiv) {}

    Forme * analyser1(std::ifstream &is) const override {
        string line;
        streampos oldpos = is.tellg(); // Sauvegarde de la position actuelle dans le fichier
        if (!getline(is, line)) {
            is.seekg(oldpos); // Retour à la ligne précédente
            return nullptr;
        }
        if (line != "groupe") {
            is.seekg(oldpos); // Retour à la ligne précédente
            return nullptr;
        }
        string couleur;
        getline(is, couleur);
        int nFormes;
        getline(is, line);
        sscanf(line.c_str(), "%d", &nFormes);
        auto *groupe = new Groupe(Forme::Couleur(strdup(couleur.c_str())));
        for (int i = 0; i < nFormes; i++) {
            unique_ptr<Forme> forme = unique_ptr<Forme>(ChargeurTxt::analyseur->analyser(is));
            groupe->add(forme);
        }
        return groupe;
    }
};

#endif //GESTIONFORME_ANALYSEURTXTGROUPE_H
