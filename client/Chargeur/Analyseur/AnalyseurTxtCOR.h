//
// Created by thomas on 16/01/24.
//

#ifndef GESTIONFORME_ANALYSEURTXTCOR_H
#define GESTIONFORME_ANALYSEURTXTCOR_H

#include "AnalyseurTxt.h"

class AnalyseurTxtCOR : public AnalyseurTxt {
    AnalyseurTxt *suivant = nullptr;

public:
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
