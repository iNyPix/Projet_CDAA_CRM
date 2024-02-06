#ifndef CRM_GESTIONPERSONNES_H
#define CRM_GESTIONPERSONNES_H
/*!
 * \file gestionpersonnes.h
 * \brief Represente une liste de personnes.
 * \author {Meryem.B Thomas.N}
 * \version 1.0
 */
#include <list>
#include "personne.h"
/*! \class GestionPersonnes.
 *  \brief Classe d'un regroupement de personnes.
 */
class GestionPersonnes {
private:
    list<Personne> lPersonnes;/*!< Regroupement de personnes^.*/
public:
    /*!
         *  \brief Constructeur.
         *
         *  Constructeur par défaut.
         */
    GestionPersonnes();
    /*!
         *  \brief Destructeur.
         *
         *  Destructeur de la classe.
         */
    ~GestionPersonnes();
    /*!
         *  \brief Recupère la liste.
         *
         *  \return La liste des personnes.
         */
    std::list<Personne> getListe() const;
    /*!
         *  \brief Taille de la liste.
         *
         *  \return Le nombre de personne dans la liste.
         */
    unsigned getSize();
    /*!
         *  \brief Recherche par nom.
         *
         *  \return Le contact avec un nom spécifique.
         */
    Personne getPersonneByName(const string &);
    //void modifContact()
    /*!
         *  \brief Suppression d'une personne.
         *
         *  Supprimme une personne de la liste
         */
    void suppPersonne(const Personne&);
    /*!
         *  \brief Ajout d'une personne.
         *
         *  \return La liste incluant la personne ajoutée.
         */
    GestionPersonnes operator+(const Personne &);
    /*!
         *  \brief Suppression d'une personne.
         *
         *  \return La liste sans la personne supprimée.
         */
    GestionPersonnes operator-(const Personne &);
    /*!
         *  \brief Remplacement de la liste.
         *
         *  \return La nouvelle liste
         */
    void operator=(const GestionPersonnes &);
    /*!
     *  \brief Affichage de la liste.
     *
     *  Méthode qui permet d'afficher les personnes de la liste.
     */
     friend ostream &operator<<( ostream &, const GestionPersonnes &);
};


#endif //CRM_GESTIONPERSONNES_H
