#ifndef PERSONNE_H
#define PERSONNE_H
/*!
 * \file personne.h
 * \brief Represente une personne avec les caractéristiques les plus simples.
 * \author {Meryem.B Thomas.N}
 * \version 1.0
 */
#include <iostream>
#include <string>
/*! \namespace std
 *
 *  Espace de nommage regroupant les methodes std.
 *
 */
using namespace std;
/*! \class Personne.
 *  \brief Classe d'une simple personne.
 */
class Personne
{
private:
    /* data */
    string nom, prenom; /*!< Nom et prenom d'une personne.*/
    int age; /*!< Age d'une personne.*/
public:
    /*!
         *  \brief Constructeur.
         *
         *  Constructeur par défaut.
         */
    Personne();
    /*!
         *  \brief Constructeur.
         *
         *  Constructeur d'une personne.
         *
         *  \param nom : le nom de la personne.
         *  \param prenom : le prenom de la personne.
         *  \param age : l'âge de la personne.
         */
    Personne(string nom, string prenom, int age);
    /*!
         *  \brief Constructeur.
         *
         *  Constructeur d'une personne.
         *
         *  \param nom : le nom de la personne.
         *  \param prenom : le prenom de la personne.
         */
    Personne(string nom, string prenom);
    /*!
         *  \brief Destructeur.
         *
         *  Destructeur de la classe.
         */
    ~Personne();
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
         *  \brief Comparer deux personnes.
         *
         *  \return true si les personnes sont les mêmes.
         */
    bool operator==(const Personne &) const;
    /*!
         *  \brief Affichage de la personne.
         *
         *  \return Un flux avec les informations de la personne.
         */
     friend ostream &operator<<( ostream &, const Personne &);

};

#endif // PERSONNE_H
