#ifndef GESTIONCONTACTS_H
#define GESTIONCONTACTS_H
/*!
 * \file gestioncontacts.h
 * \brief Represente une liste de contacts.
 * \author {Meryem.B Thomas.N}
 * \version 1.0
 */
#include <QObject>
#include <list>
#include "contact.h"

using namespace std;
/*! \class GestionContacts.
 *  \brief Classe d'un regroupement de contacts.
 */
class GestionContacts
{
private:
    list<Contact> lContacts; /*!< Regroupement de contacts.*/
public:
    /*!
          *  \brief Constructeur.
          *
          *  Constructeur par défaut.
          */
    GestionContacts();
    /*!
         *  \brief Destructeur.
         *
         *  Destructeur de la classe.
         */
    ~GestionContacts();
    /*!
          *  \brief Initialise la liste de contacts.
          *
          *  Permet de modifier la list contenant les contacts
          */
    void setListContacts(list<Contact> lContacts);
    /*!
         *  \brief La liste.
         *
         *  \return La liste de contacts.
         */
    list<Contact> getListContacts() const;
    list<Contact>& getListContacts();
    /*!
          *  \brief Recherche par le nom.
          *
          *  \return Le contact avec un nom spécifique.
          */
    Contact getContactByName(const string &);
    /*!
          *  \brief Recherche par l'entreprise.
          *
          *  \return Le contact travaillant dans une entreprise spécifique.
          */
    Contact getContactByEntreprise(const string &);
    /*!
          *  \brief Recherche par le nom ET prenom.
          *
          *  \return Le contact qui a un nom ET prenom spécifique.
          */
    Contact getContactByNameSurname(const string &, const string &);
    /*!
          *  \brief Recherche par date.
          *
          *  \return Les contacts créés à une certaine date.
          */
    Contact getContactByDate(Date &);
    /*!
          *  \brief Recherche par date.
          *
          *  \return Les contacts créés entre deux dates.
          */
    GestionContacts getContactsByIntervalle(Date &, Date &);
    /*!
          *  \brief Recherche par le nom.
          *
          *  \return Le contact avec un nom spécifique.
          */
    Contact* getContactById(const int &);
    /*!
          *  \brief Nombre de contacts.
          *
          *  \return Taille de la liste.
          */
    int getNbrContacts();
    /*!
        *  \brief Tri par date de création
        *
        *  Méthode qui permet de trier la liste des contacts par date de création
    */
    void trier_date_creation(list<Contact> &);
    /*!
          *  \brief Ajout d'un contact.
          *
          *  \return La liste incluant le contact ajouté.
          */
    GestionContacts operator+(const Contact &);
    /*!
          *  \brief Remplacement de la liste.
          *
          *  \return Remplace une liste par une autre
          */
    void operator=(const GestionContacts &);
    /*!
          *  \brief Suppression d'un contact.
          *
          *  \return La liste sans le contact supprimé.
          */
    GestionContacts operator-(const Contact &);

    //void modifContact()
    /*!
         *  \brief Suppression d'un contact.
         *
         */
    void suppContact(Contact &);
    /*!
     *  \brief Affichage de la liste.
     *
     *  Méthode qui permet d'afficher les contacts de la liste.
     */
    friend ostream &operator<<( ostream &, const GestionContacts &);
    /*!
             *  \brief Ajout d'un contact.
             *
            */
    void ajoutContact(Contact &);
};

#endif // GESTIONCONTACTS_H
