//
// Created by thomas on 23/10/23.
//
#include "gestionpersonnes.h"

GestionPersonnes::GestionPersonnes() {

}
GestionPersonnes::~GestionPersonnes() {

}

std::list<Personne> GestionPersonnes::getListe() const {
    return lPersonnes;
}

Personne GestionPersonnes::getPersonneByName(const string &n) {
    Personne p1;
    for (const Personne &p: lPersonnes)
        if (p.getNom() == n) p1 = p;
    return p1;
}

GestionPersonnes GestionPersonnes::operator+(const Personne &p) {
    lPersonnes.push_back(p);
    return *this;
}

void GestionPersonnes::operator=(const GestionPersonnes &gp) {
    lPersonnes.clear();
    lPersonnes = gp.lPersonnes;
}


GestionPersonnes GestionPersonnes::operator-(const Personne &p)
{
    auto it = lPersonnes.begin();
    bool found = false;
    while ((it != lPersonnes.end()) && !found) {
        if (*it == p) //operator== de Personne
        {
            found = true;
            it = lPersonnes.erase(it);
        } else
            ++it;
    }
    return *this;
}

unsigned GestionPersonnes::getSize() {
    return lPersonnes.size();
}

ostream &operator<<(ostream& os, const GestionPersonnes& gp)
{
    for(Personne p : gp.getListe())
    {
        os << '-' << p << endl;
    }
    return os;
}
