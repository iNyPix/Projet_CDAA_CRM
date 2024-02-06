#ifndef CONTACT_H
#define CONTACT_H

/*!
 * \file contact.h
 * \brief Represente une fiche contact.
 * \author {Meryem.B Thomas.N}
 * \version 1.0
 */

#include "personne.h"
#include "date.h"
#include <string>
#include <ctime>
#include <list>
#include "gestioninteractions.h"

/*! \namespace std
 *
 *  Espace de nommage regroupant les methodes std.
 *
 */
using namespace std;

/*! \class Contact.
 *  \brief Classe représentant une fiche contact.
 */
class Contact : public Personne
{
private:
    int idContact; /*!< Identifiant du contact.*/
    string nom, prenom; /*!< Nom et prenom d'une personne.*/
    int age; /*!< Age d'une personne.*/
    string entreprise, mail, telephone,urlPhoto;
    Date creation; /*!< Date de création du contact.*/
    Date modification; /*!< Date de modification du contact.*/
    GestionInteractions gt;
public:
    /*!
         *  \brief Constructeur.
         *
         *  Constructeur par défaut.
         */
    Contact();
    /*!
         *  \brief Constructeur.
         *
         *  Constructeur de la classe Contact.
         *
         *  \param nom : nom du contact.
         *  \param prenom : prenom du contact.
         *  \param age : age du contact.
         *  \param entreprise : entreprise de ce contact.
         *  \param mail : mail de ce contact.
         *  \param telephone : telephone de ce contact.
         *  \param urlPhoto : lien vers la photo du contact.
         */
    Contact(string nom, string prenom, int age, string, string, string, string);
    /*!
         *  \brief Destructeur.
         *
         *  Destructeur de la classe Contact.
         */
    ~Contact();
    /*!
         *  \brief Identifiant.
         *
         *  \return un entier qui représente l'id.
         */
    int getId() const;
    /*!
         *  \brief Obtenir le nom.
         *
         *  \return Le nom de la personne.
         */
    string getNom() const;
    /*!
         *  \brief Obtenir le prénom.
         *
         *  \return Le prénom de la personne.
         */
    string getPrenom() const;
    /*!
         *  \brief Obtenir l'âge.
         *
         *  \return L'âge de la personne.
         */
    int getAge() const;
    /*!
         *  \brief Definir le nom.
         *
         *  Specifie le nom de la personne.
         */
    void setNom(string);
    /*!
         *  \brief Definir le prénom.
         *
         *  Specifie le prénom de la personne.
         */
    void setPrenom(string);
    /*!
         *  \brief Definir l'âge.
         *
         *  Specifie l'âge de la personne.
         */
    void setAge(int);
    /*!
         *  \brief Entreprise.
         *
         *  \return le nom de l'entreprise.
         */
    string getEntreprise() const;
    /*!
         *  \brief Mail.
         *
         *  \return le mail du contact.
         */
    string getMail() const;
    /*!
         *  \brief Téléphone.
         *
         *  \return le numero du contact.
         */
    string getTelephone() const;
    /*!
         *  \brief UrlPhoto.
         *
         *  \return lien vers la photo.
         */
    string getUrlPhoto() const;
    /*!
         *  \brief Date création.
         *
         *  \return la date de création de la fiche.
         */
    Date getCreation() const;
    /*!
         *  \brief Date modification.
         *
         *  \return la date de modification de la fiche.
         */
    Date getModification() const;
    /*!
         *  \brief Intéractions.
         *
         *  \return liste des intéractions du contact.
         */
    GestionInteractions* getGestInteraction();
    /*!
         *  \brief Intéractions.
         *
         *  \return liste des intéractions du contact.
         */
    GestionInteractions getGestInt();
    /*!
     *  \brief Ajout l'entreprise.
     *
     *  Méthode qui permet d'ajouter le nom de l'entreprise du contact.
     */
    void setEntreprise(string );
    /*!
     *  \brief Ajout le mail.
     *
     *  Méthode qui permet d'ajouter le mail du contact.
     */
    void setMail(string );
    /*!
     *  \brief Ajout le telephone.
     *
     *  Méthode qui permet d'ajouter le numero de téléphone du contact.
     */
    void setTelephone(string );
    /*!
     *  \brief Ajout du lien photo.
     *
     *  Méthode qui permet d'ajouter le lien vers la photo du contact.
     */
    void setUrlPhoto(string );
    /*!
     *  \brief Ajout de la création.
     *
     *  Méthode qui permet d'ajouter la date de création du contact.
     */
    void setCreation(Date);
    /*!
     *  \brief Ajout de la modification.
     *
     *  Méthode qui permet d'ajouter la date de modification du contact.
     */
    void setModification();
    /*!
     *  \brief Ajout de la modification.
     *
     *  Méthode qui permet d'ajouter la date de modification du contact.
     */
    void setModification(Date);
    /*!
     *  \brief Ajout de l'id.
     *
     *  Méthode qui permet de définir l'id du contact.
     */
    void setId(int);
    /*!
     *  \brief Affichage du contact.
     *
     *  Méthode qui permet d'afficher les informations d'un contact.
     */
    friend ostream &operator<<( ostream &, const Contact &);
};

#endif // CONTACT_H
