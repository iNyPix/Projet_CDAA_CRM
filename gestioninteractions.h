#ifndef GESTIONINTERACTIONS_H
#define GESTIONINTERACTIONS_H
#include "interaction.h"
#include <list>

class GestionInteractions
{
private:
    list<Interaction> linteractions; /*!< Intéractions du contact.*/
public:
    /*!
          *  \brief Constructeur.
          *
          *  Constructeur par défaut.
          */
    GestionInteractions();
    /*!
         *  \brief Destructeur.
         *
         *  Destructeur de la classe.
         */
    ~GestionInteractions();
    /*!
         *  \brief Liste des interactions.
         *
         * \return La liste qui contient les interactions
         */
    list<Interaction> getList();
    /*!
     *  \brief Ajout intéraction.
     *
     *  Méthode qui permet d'ajouter une/des intéraction(s) du contact.
     */
    void addInteraction(Interaction &);
    /*!
     *  \brief Suppression intéraction.
     *
     *  Méthode qui permet de supprimer une/des intéraction(s) du contact.
     */
    void suppInteraction(int id);
    /*!
     *  \brief Taille de la liste d'intéractions.
     *
     *  \return Le nombre d'intéractions dans la liste.
     */
    int getSize();
    /*!
     *  \brief Recherche intéraction.
     *
     *  Méthode qui permet de rechercher une interaction du contact.
     */
    Interaction rechInteraction(Interaction &);
    /*!
     *  \brief Recherche intéraction avec id.
     *
     *  Méthode qui permet de rechercher une interaction du contact.
     */
    Interaction* rechInteraction(int id);
    /*!
     *  \brief Trier par date de modification.
     *
     *  Méthode qui permet de trier les interaction du contact par date de modification.
     */
    void trier_date_modification(list<Interaction> &liste);
};

#endif // GESTIONINTERACTIONS_H
