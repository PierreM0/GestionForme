//
// Created by thomas on 16/01/24.
//

#include "ChargeurTxt.h"
#include "Analyseur/AnalyseurTxtSegment.h"
#include "Analyseur/AnalyseurTxtPolygone.h"
#include "Analyseur/AnalyseurTxtTriangle.h"
#include "Analyseur/AnalyseurTxtCercle.h"
#include "Analyseur/AnalyseurTxtGroupe.h"

AnalyseurTxt *ChargeurTxt::analyseur = nullptr;

Forme *ChargeurTxt::charger(const std::string &chemin) {
    if (analyseur == nullptr) {
        analyseur = new AnalyseurTxtSegment(nullptr);
        analyseur = new AnalyseurTxtPolygone(analyseur);
        analyseur = new AnalyseurTxtTriangle(analyseur);
        analyseur = new AnalyseurTxtCercle(analyseur);
        analyseur = new AnalyseurTxtGroupe(analyseur);
    }
    ifstream fichier(chemin);
    return analyseur->analyser(fichier);
}