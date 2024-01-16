//
// Created by thomas on 15/01/24.
//

#ifndef GESTIONFORME_SAUVEGARDEURTXT_H
#define GESTIONFORME_SAUVEGARDEURTXT_H

#include <string>

using namespace std;

class Segment;
class Polygone;
class Triangle;
class Cercle;
class Groupe;

/**
 * Cette classe permet la sauvegarde d'une forme dans un fichier texte
 */
class SauvegardeurTxt {
public:

    /**
     * Sauvegarde un segment donné dans un fichier de chemin donné.
     * @param forme : le segment
     * @param chemin : le chemin du fichier, vide si la fonction ne doit pas écrire dans le fichier
     * @return le contenu du fichier de sauvegarde
     */
    const string &sauvegarder(const Segment &forme, const string &chemin) const;

    /**
     * Sauvegarde un polygone donné dans un fichier de chemin donné.
     * @param forme : le polygone
     * @param chemin : le chemin du fichier, vide si la fonction ne doit pas écrire dans le fichier
     * @return le contenu du fichier de sauvegarde
     */
    const string & sauvegarder(const Polygone &forme, const string &chemin) const;

    /**
     * Sauvegarde un triangle donné dans un fichier de chemin donné.
     * @param forme : le triange
     * @param chemin : le chemin du fichier, vide si la fonction ne doit pas écrire dans le fichier
     * @return le contenu du fichier de sauvegarde
     */
    const string &sauvegarder(const Triangle &forme, const string &chemin) const;

    /**
     * Sauvegarde un cercle donné dans un fichier de chemin donné.
     * @param forme : le cercle
     * @param chemin : le chemin du fichier, vide si la fonction ne doit pas écrire dans le fichier
     * @return le contenu du fichier de sauvegarde
     */
    const string &sauvegarder(const Cercle &forme, const string &chemin) const;

    /**
     * Sauvegarde un groupe de formes donné dans un fichier de chemin donné.
     * @param forme : le groupe de formes
     * @param chemin : le chemin du fichier, vide si la fonction ne doit pas écrire dans le fichier
     * @return le contenu du fichier de sauvegarde
     */
    const string &sauvegarder(const Groupe &forme, const string &chemin) const;
};

#endif //GESTIONFORME_SAUVEGARDEURTXT_H
