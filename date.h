#ifndef DATE_H
#define DATE_H
/*!
 * \file date.h
 * \brief Represente la structure d'une date.
 * \author {Meryem.B Thomas.N}
 * \version 1.0
 */
#include <string>
#include <iostream>
/*! \namespace std
 *
 *  Espace de nommage regroupant les methodes std.
 *
 */
using namespace std;
/*! \class Date.
 *  \brief Classe d'une date.
 */
class Date
{
private:
    unsigned jour;/*!< Jour d'une date.*/
    unsigned mois;/*!< Mois d'une date.*/
    unsigned annee;/*!< Année d'une date.*/

public:
    /*!
         *  \brief Constructeur.
         *
         *  Constructeur par défaut.
         */
    Date();
    /*!
         *  \brief Constructeur.
         *
         *  Constructeur pour définir une date.
         *
         *  \param string : date sous la forme jj/mm/aaaa.
         */
    Date(string);
    /*!
         *  \brief Constructeur.
         *
         *  Constructeur pour définir une date précise.
         *
         *  \param jour : jour de la date.
         *  \param mois : mois de la date.
         *  \param annee : annee de la date.
         */
    Date(unsigned, unsigned, unsigned);
    /*!
         *  \brief Destructeur.
         *
         *  Destructeur par défaut.
         *
         */
    ~Date();
    /*!
         *  \brief Le jour.
         *
         *  \return La journée de la date.
         */
    unsigned getJour() const;
    /*!
         *  \brief Le mois.
         *
         *  \return Le mois de la date.
         */
    unsigned getMois() const;
    /*!
         *  \brief L'année.
         *
         *  \return L'année de la date.
         */
    unsigned getAnnee() const;
    /*!
         *  \brief Aujourd'hui.
         *
         *  \return La date courante.
         */
    static Date getDateActuelle();
    /*!
         *  \brief Definition du jour.
         *
         */
    void setJour(unsigned &);
    /*!
         *  \brief Definition du mois.
         *
         */
    void setMois(unsigned &);
    /*!
         *  \brief Definition de l'année.
         *
         */
    void setAnnee(unsigned &);
    /*!
         *  \brief Affichage de date.
         *
         *  \return Affichage de date sous forme de string
         */
    string affiche();
    /*!
         *  \brief Comparaison de date.
         *
         *  \return Si une date est plus grande que l'autre ou pas
         */
    bool operator<(const Date &);
    /*!
         *  \brief Comparaison de date.
         *
         *  \return Si les dates sont les mêmes
         */
    bool operator==(const Date &);
    /*!
         *  \brief Comparaison de date.
         *
         *  \return Si les dates sont les mêmes ou superieur
         */
    bool operator>=(const Date &);
    /*!
         *  \brief Comparaison de date.
         *
         *  \return Si les dates sont les mêmes ou inferieur
         */
    bool operator<=(const Date &);
    /*!
         *  \brief Affichage de date.
         *
         *  Affiche la date sous la forme dd/mm/aaaa
         */
    friend ostream &operator<<( ostream &, const Date &);
};

#endif // DATE_H
