//
// Created by thomas on 16/01/24.
//

#ifndef GESTIONFORME_CHARGEURTXT_H
#define GESTIONFORME_CHARGEURTXT_H

#include <string>
#include "Analyseur/AnalyseurTxt.h"

using namespace std;

class Forme;

/**
 * Cette classe permet le chargement en memoire d'une forme depuis un fichier texte
 */
class ChargeurTxt {
public:
    static AnalyseurTxt *analyseur;

    static Forme *charger(const string &chemin);
};

#endif //GESTIONFORME_CHARGEURTXT_H
