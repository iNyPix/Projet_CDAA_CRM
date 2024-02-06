#include "interaction.h"
#include "date.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

Interaction::Interaction()
{
}
Interaction::Interaction(const string & c, int idC)
{
    this->setDate(Date::getDateActuelle());
    this->setDateModif();
    this->setContenu(c);
    this->setIdContact(idC);
}
Interaction::Interaction(const Date & d, const string & c, int idC)
{
    this->setDate(d);
    this->setContenu(c);
    this->setIdContact(idC);
}
Interaction::~Interaction()
{
}
Date Interaction::getDate() const
{
    return date;
}
Date Interaction::getDateModif() const
{
    return modification;
}
std::string Interaction::getContenu() const
{
    return contenu;
}
int Interaction::getId() const
{
    return idInteraction;
}
int Interaction::getIdContact() const
{
    return idContact;
}
void Interaction::setDate(const Date & d)
{
    date = d;
}
void Interaction::setDateModif()
{
    modification = Date::getDateActuelle();
}
void Interaction::setDateModifD(Date d)
{
    modification = d;
}
void Interaction::setContenu(const string & c)
{
    contenu = c;
}
void Interaction::setId(int i)
{
    idInteraction = i;
}
void Interaction::setIdContact(int id)
{
    idContact = id;
}
string Interaction::affiche(){
    return getContenu();
}
ostream& operator<<(ostream & os, const Interaction & i)
{

    Date d = i.getDate();
    os << d.getJour() << "-" << d.getMois() << "-" << d.getAnnee() << " "<< i.getContenu();
    return os;
}
