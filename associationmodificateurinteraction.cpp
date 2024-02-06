//
// Created by thomas on 25/10/23.
//

#include "associationmodificateurinteraction.h"

AssociationModificateurInteraction::AssociationModificateurInteraction()
{}
AssociationModificateurInteraction::~AssociationModificateurInteraction()
{
    delete(this->modificateur);
    delete(this->interaction);
}

void AssociationModificateurInteraction::setMod(Modificateur *mod)
{
    this->modificateur = mod;
}
void AssociationModificateurInteraction::setInteraction(Interaction *inter)
{
    this->interaction = inter;
}
Modificateur* AssociationModificateurInteraction::getModif()
{
    return modificateur;
}
Interaction* AssociationModificateurInteraction::getInteraction()
{
    return interaction;
}
