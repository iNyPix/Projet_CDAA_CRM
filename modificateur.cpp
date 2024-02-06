#include "modificateur.h"

Modificateur::Modificateur(const Personne &p, const Date &d)
{
    this->setPrenom(p.getPrenom());
    this->setNom(p.getNom());
    this->modification = d;
}

Modificateur::~Modificateur()
{
}
