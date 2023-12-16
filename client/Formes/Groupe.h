//
// Created by pierrem on 16/12/23.
//

#ifndef GROUPE_H
#define GROUPE_H
#include <memory>
#include <vector>

#include "Forme.h"

class  Groupe : public Forme
{

/// Only one forme of each.
vector<unique_ptr<Forme>> formes;

public:
    explicit Groupe(const Couleur &color)
        : Forme(color)
    {
    }

    void add(const unique_ptr<Forme> &f)
    {

        formes.push_back(f);
    }

    void translation(const Vecteur2D& translation) override
    {
        for (auto f: formes)
        {
           f->translation(translation);
        }
    }
    void homotetie(const Point2D& point_invariant, const double& rapport) override
    {
        for (auto f: formes)
        {
           f->homotetie(point_invariant, rapport);
        }
    }
    void rotation(const Point2D& point_invariant, const double& theta) override
    {
        for (auto f: formes)
        {
           f->rotation(point_invariant, theta);
        }
    }

    bool operator==(const Forme& f) const override
    {
        const Groupe *g;
        if ((g = dynamic_cast<const Groupe*>(&f)) == nullptr)
         return false;
        for (auto forme: formes)
        {
         bool found = false;
         for (const auto gforme: g->formes)
         if (*forme == *gforme) {
            found = true;
            break;
         }
         if (!found)
             return false;
        }

        return true;
    }

    operator string() const override
    {
        ostringstream s;
        s << "Groupe: " << endl;
        for (auto forme: formes)
        {
            s << "    " << string(*forme) << endl;
        }
        return s.str();
    }
};

#endif //!GROUPE_H
