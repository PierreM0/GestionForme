//
// Created by thomas on 15/01/24.
//

using namespace std;

#include <iostream>
#include <sstream>
#include <fstream>
#include "SauvegardeurTxt.h"
#include "../Formes/Groupe.h"
#include "../Formes/FormeSimple/Cercle.h"
#include "../Formes/FormeSimple/Polygone.h"
#include "../Formes/FormeSimple/Segment.h"
#include "../Formes/FormeSimple/Triangle.h"

void saveIfNeeded(const string &path, const string &content) {
    if (path.empty()) return;
    ofstream file(path);
    file << content;
    file.close();
}

const string &SauvegardeurTxt::sauvegarder(const Segment &forme, const std::string &chemin) const {
    stringstream ss;
    ss << "segment\n"
    << forme.color.getContent() << "\n"
    << forme.a.x << " " << forme.a.y << "\n"
    << forme.b.x << " " << forme.b.y << "\n";
    auto *content = new string(ss.str());
    saveIfNeeded(chemin, *content);
    return *content;
}

const string &SauvegardeurTxt::sauvegarder(const Polygone &forme, const std::string &chemin) const {
    stringstream ss;
    ss << "polygone\n"
    << forme.color.getContent() << "\n"
    << forme.points.size() << "\n";
    for (Point2D p : forme.points)
        ss << p.x << " " << p.y << "\n";
    auto *content = new string(ss.str());
    saveIfNeeded(chemin, *content);
    return *content;
}

const string &SauvegardeurTxt::sauvegarder(const Triangle &forme, const std::string &chemin) const {
    stringstream ss;
    ss << "triangle\n"
    << forme.color.getContent() << "\n"
    << forme.a.x << " " << forme.a.y << "\n"
    << forme.b.x << " " << forme.b.y << "\n"
    << forme.c.x << " " << forme.c.y << "\n";
    auto *content = new string(ss.str());
    saveIfNeeded(chemin, *content);
    return *content;
}

const string &SauvegardeurTxt::sauvegarder(const Cercle &forme, const std::string &chemin) const {
    stringstream ss;
    ss << "cercle\n"
    << forme.color.getContent() << "\n"
    << forme.c.x << " " << forme.c.y << "\n"
    << forme.rayon << "\n";
    auto *content = new string(ss.str());
    saveIfNeeded(chemin, *content);
    return *content;
}

const string &SauvegardeurTxt::sauvegarder(const Groupe &groupe, const std::string &chemin) const {
    stringstream ss;
    ss << "groupe\n"
    << groupe.color.getContent() << "\n"
    << groupe.formes.size() << "\n";
    for (auto &f : groupe.formes) {
        string content = f->sauvegarder(*this, "");
        ss << content;
    }
    auto *content = new string(ss.str());
    saveIfNeeded(chemin, *content);
    return *content;
}