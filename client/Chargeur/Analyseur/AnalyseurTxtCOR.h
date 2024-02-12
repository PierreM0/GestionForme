//
// Created by thomas on 16/01/24.
//

#ifndef GESTIONFORME_ANALYSEURTXTCOR_H
#define GESTIONFORME_ANALYSEURTXTCOR_H

#include "AnalyseurTxt.h"

/**
 * Représente un maillon d'une chaîne de responsabilité permettant de parser une forme à partir d'un fichier texte
 */
class AnalyseurTxtCOR : public AnalyseurTxt {
    AnalyseurTxt *suivant = nullptr;

public:

    /**
     * Crée un maillon en donnant le maillon suivant
     * @param suiv le maillon suivant
     */
    AnalyseurTxtCOR(AnalyseurTxt *suiv) : suivant(suiv) {}

    Forme* analyser(ifstream &is) const override {
        Forme* res = analyser1(is);
        if (res != nullptr)
            return res;
        if (suivant == nullptr)
            return nullptr;
        return suivant->analyser(is);
    }

    virtual Forme* analyser1(ifstream &is) const = 0;
};

#endif //GESTIONFORME_ANALYSEURTXTCOR_H
