//
// Created by thomas on 16/01/24.
//

#ifndef GESTIONFORME_ANALYSEURTXT_H
#define GESTIONFORME_ANALYSEURTXT_H

#include <fstream>
#include "../../Formes/Forme.h"

class AnalyseurTxt {
public:
    virtual Forme* analyser(ifstream &is) const = 0;
};

#endif //GESTIONFORME_ANALYSEURTXT_H
