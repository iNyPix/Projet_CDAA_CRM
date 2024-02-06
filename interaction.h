#ifndef INTERACTION_H
#define INTERACTION_H
/*!
 * \file contact.h
 * \brief Represente une interaction.
 * \author {Meryem.B Thomas.N}
 * \version 1.0
 */
#include <ostream>
#include <ctime>
#include <string>
#include "date.h"
/*! \namespace std
 *
 *  Espace de nommage regroupant les methodes std.
 *
 */
using namespace std;
/*! \class Interaction.
 *  \brief Classe d'une interaction.
 */
class Interaction
{
private:
    int idInteraction; /*!< Identifiant de l'interaction.*/
    int idContact;
    Date date;/*!< Date de l'interaction.*/
    Date modification;/*!< Date de modification de l'interaction.*/
    string contenu; /*!< Contenu de l'interaction.*/

public:
    /*!
         *  \brief Constructeur.
         *
         *  Constructeur par défaut.
         */
    Interaction();
    /*!
         *  \brief Constructeur.
         *
         *  Constructeur d'un interaction avec son contenu.
         *
         *  \param contenu : contenu de l'intéraction.
         */
    Interaction(const string & c, int idC);
    /*!
         *  \brief Constructeur.
         *
         *  Constructeur de l'interaction à tel date.
         *
         *  \param contenu : contenu de l'intéraction.
         *  \param entreprise : date de l'interaction.
         */
    Interaction(const Date &, const string &, int idC);
    /*!
         *  \brief Destructeur.
         *
         *  Destructeur de la classe.
         */
    ~Interaction();
    /*!
         *  \brief Obtenir la date.
         *
         *  \return La date enregistré.
         */
    Date getDate() const;
    /*!
         *  \brief Obtenir la date de modification.
         *
         *  \return La date de modification.
         */
    Date getDateModif() const;
    /*!
         *  \brief Contenu.
         *
         *  \return Le contenu de l'interaction.
         */
    string getContenu() const;
    /*!
         *  \brief Identifiant de l'interaction.
         *
         *  \return L'entier représentant l'identifiant.
         */
    int getId() const;
    /*!
         *  \brief Identifiant du contact de l'interaction.
         *
         *  \return L'entier représentant l'identifiant.
         */
    int getIdContact() const;
    /*!
         *  \brief Paramétrer la date.
         *
         *  Indiquer la date de l'interaction
         */
    void setDate(const Date &);
    /*!
         *  \brief Paramétrer la date de modification.
         *
         *  Indiquer la date de modification de l'interaction
         */
    void setDateModif();
    /*!
         *  \brief Paramétrer la date de modification.
         *
         *  Indiquer la date de modification de l'interaction
         */
    void setDateModifD( Date);
    /*!
         *  \brief Paramétrer le contenu.
         *
         *  Indiquer le contenu de l'interaction
         */
    void setContenu(const string &);
    /*!
         *  \brief Paramétrer l'id.
         *
         *  Spécifie l'identifiant de l'interaction.
         */
    void setId(int);
    /*!
         *  \brief Paramétrer l'id du contact.
         *
         *  Spécifie l'identifiant du contact de l'interaction.
         */
    void setIdContact(int);
    /*!
         *  \brief Affichage de l'interaction.
         *
         *  \return Les détails de l'interaction.
         */
    string affiche();
    /*!
         *  \brief Affichage de l'interaction.
         *
         *  \return un flux avec les détails de l'interaction.
         */
    friend ostream& operator<<(ostream &, const Interaction &);
};

#endif // INTERACTION_H
