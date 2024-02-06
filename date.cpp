#include "date.h"
#include <ctime>

// Constructeurs
Date::Date()
{
}

Date::Date(string d) // jj/mm/aaaa
{
    int i1 = d.find_first_of('/');
    int i2 = d.find_first_of('/', i1 + 1);

    this->jour = stoi(d.substr(0 , i1));
    this->mois = stoi(d.substr(i1 +1 , i2 -i1 -1));
    this->annee = stoi(d.substr(i2 +1));
}

// Destructeur
Date::~Date()
{
}
// Getters
unsigned Date::getJour() const
{
    return this->jour;
}
unsigned Date::getMois() const
{
    return this->mois;
}
unsigned Date::getAnnee() const
{
    return this->annee;
}
// Setters
void Date::setJour(unsigned &j)
{
    this->jour = j;
}
void Date::setMois(unsigned &m)
{
    this->mois = m;
}
void Date::setAnnee(unsigned &a)
{
    this->annee = a;
}

Date::Date(unsigned j, unsigned m, unsigned a) {
    this->jour = j;
    this->mois=m;
    this->annee=a;
}

// Méthodes
Date Date::getDateActuelle()
{
    const unsigned BASE_YEAR = 1900; // Année de reference
    time_t timer = time(NULL);       // Renvoie l'heure actuelle en secondes depuis l'époque Unix (le 1er janvier 1970 à 00:00:00 UTC)
    tm *time;                        // Structure de la date
    std::time(&timer);               // Met à jour la valeur de la variable timer
    time = std::localtime(&timer);   // Converti le nombre de secondes en une structure

    Date actuelle(time->tm_mday, time->tm_mon +1, time->tm_year + BASE_YEAR);

    return actuelle;
}
string Date::affiche()
{
    return to_string(jour) + "/" + to_string(mois) + "/" + to_string(annee);
}

bool Date::operator==(const Date &d)
{
    bool b = false;
    if(getJour() == d.getJour())
        if(getMois() == d.getMois())
            if(getAnnee() == d.getAnnee())
                b = true;
    return b;
}

bool Date::operator<(const Date &d)
{
    bool b = false;
    if (getAnnee() < d.getAnnee()) {
        b = true;
    } else if (getAnnee() > d.getAnnee()) {
        b = false;
    } else {  // Les années sont égales, vérifions les mois
        if (getMois() < d.getMois()) {
            b =  true;
        } else if (getMois() > d.getMois()) {
            b = false;
        } else {  // Les mois sont égaux, vérifions les jours
            b = getJour() < d.getJour();
        }
    }
    return b;
}

bool Date::operator<=(const Date &date)
{
    return  *this < date || *this == date;
}

bool Date::operator>=(const Date &d)  {
    return !(*this < d);
}

ostream &operator<<( ostream& os, const Date& d)
{
    os << d.jour << "/" << d.mois << "/" << d.annee;
    return os;
}
