//
// Created by thomas on 16/01/24.
//

#ifndef GESTIONFORME_ANALYSEURTXT_H
#define GESTIONFORME_ANALYSEURTXT_H

#include <fstream>
#include "../../Formes/Forme.h"

/**
 * Classe permettant le parsing d'une forme à partir d'un fichier texte
 */
class AnalyseurTxt {
public:

    /**
     * Parse une forme à partir du flux d'entrée du fichier texte
     * @param is le flux d'entrée
     * @return la forme
     */
    virtual Forme* analyser(ifstream &is) const = 0;
};

#endif //GESTIONFORME_ANALYSEURTXT_H
