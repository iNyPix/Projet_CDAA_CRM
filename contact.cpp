#include "contact.h"

Contact::Contact()
{
    setCreation(Date::getDateActuelle());
}
Contact::Contact(string nom, string prenom, int age, string ent, string mail, string tel, string url)
{
    setCreation(Date::getDateActuelle());
    setModification(Date::getDateActuelle());
    setNom(nom);
    setPrenom(prenom);
    setAge(age);
    setEntreprise(ent);
    setMail(mail);
    setTelephone(tel);
    setUrlPhoto(url);
}
Contact::~Contact(){}

GestionInteractions* Contact::getGestInteraction()
{
    return &gt;
}

GestionInteractions Contact::getGestInt()
{
    return gt;
}

string Contact::getNom() const
{
    return nom;
}

string Contact::getPrenom() const
{
    return prenom;
}

int Contact::getAge() const
{
    return age;
}

void Contact::setNom(string n)
{
    nom = n;
}

void Contact::setPrenom(string p)
{
    prenom = p;
}

void Contact::setAge(int a)
{
    age = a;
}

string Contact::getEntreprise() const
{
    return entreprise;
}
string Contact::getMail() const
{
    return mail;
}
string Contact::getTelephone() const
{
    return telephone;
}
string Contact::getUrlPhoto() const
{
    return urlPhoto;
}
Date Contact::getCreation() const
{
    return creation;
}
Date Contact::getModification() const
{
    return modification;
}
int Contact::getId() const
{
    return idContact;
}
void Contact::setEntreprise(string en)
{
    this->entreprise = en;
}
void Contact::setMail(string m)
{
    this->mail = m;
}
void Contact::setTelephone(string t)
{
    this->telephone = t;
}
void Contact::setUrlPhoto(string up)
{
    this->urlPhoto = up;
}
void Contact::setCreation(Date creation)
{
    this->creation = creation;
}
void Contact::setModification()
{
    this->modification = Date::getDateActuelle();
}
void Contact::setModification(Date d)
{
    this->modification = d;
}
void Contact::setId(int id)
{
    this->idContact = id;
}

ostream& operator<<( ostream& os,const Contact& c )
{
    os << c.getNom() << " " << c.getPrenom() << " " << c.getTelephone() << " " << c.getMail() << " " << c.getCreation() << " " << c.getUrlPhoto();
    return os;
}
