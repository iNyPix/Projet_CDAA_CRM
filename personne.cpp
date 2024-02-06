#include "personne.h"

//Constructor
Personne::Personne(){}
Personne::Personne(string nom, string prenom, int age)
{
    this->nom = nom;
    this->prenom = prenom;
    this->age = age;
}
Personne::Personne(string nom, string prenom)
{
    this->nom = nom;
    this->prenom = prenom;
}
//Destructor
Personne::~Personne()
{
}
//Getters
string Personne::getNom() const {
    return nom;
}
string Personne::getPrenom() const {
    return prenom;
}
int Personne::getAge() const {
    return age;
}
//Setters
void Personne::setNom(string n)
{
    this->nom = n;
}
void Personne::setPrenom(string p)
{
    this->prenom = p;
}
void Personne::setAge(int a)
{
    this->age = a;
}

bool Personne::operator==(const Personne &p) const {
    if (getAge() == p.getAge())
        if (getNom() == p.getNom())
            if (getPrenom() == p.getPrenom())
                return true;
    return false;
}

 ostream &operator<<( ostream& os, const Personne& p )
{
     os << p.getNom() << " " << p.getPrenom() ;
     return os;
}
