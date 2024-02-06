#ifndef TODO_H
#define TODO_H
/*!
 * \file todo.h
 * \brief Represente un todo.
 * \author {Meryem.B Thomas.N}
 * \version 1.0
 */
#include "date.h"
#include <string>
#include <iostream>
/*! \namespace std
 *
 *  Espace de nommage regroupant les methodes std.
 *
 */
using namespace std;
/*! \class Todo.
 *  \brief Classe d'un todo.
 */
class Todo
{
private:
    /* data */
    int idTodo;
    string contenu; /*!< Contenu du todo.*/
    Date date; /*!< Date du todo.*/
public:
    /*!
         *  \brief Constructeur.
         *
         *  Constructeur par défaut.
         */
    Todo();
    /*!
         *  \brief Constructeur.
         *
         *  Constructeur d'un todo.
         *-
         *  \param string : contenu de du todo.
         */
    Todo(string);
    /*!
         *  \brief Constructeur.
         *
         *  Constructeur d'un todo.
         *
         *  \param string : contenu de du todo.
         *  \param date : date du todo.
         */
    Todo(string, Date);
    /*!
         *  \brief Destructeur.
         *
         *  Destructeur de la classe.
         */
    ~Todo();
    /*!
         *  \brief Obtenir le contenu.
         *
         *  \return Le contenu du todo.
         */
    string getContenu();
    /*!
         *  \brief Obtenir la date.
         *
         *  \return La date du todo.
         */
    Date getDate();
    /*!
         *  \brief Obtenir l'id.
         *
         *  \return L'id du todo.
         */
    int getId() const;
    /*!
         *  \brief Définition du contenu.
         *
         *  Spécifié le contenu du todo.
         */
    void setContenu(string );
    /*!
         *  \brief Définition de la date.
         *
         *  Spécifié la date du todo.
         */
    void setDate(Date );
    /*!
         *  \brief Définition de l'id.
         *
         *  Spécifié l'id du todo.
         */
    void setId(int);
    /*!
         *  \brief Affichage du todo.
         *
         *  \return Les informations du todo.
         */
    string affiche();
    /*!
         *  \brief Affichage du todo.
         *
         *  \return Flux avec les informations du todo.
         */
    friend ostream &operator<<( ostream& os, const Todo&);
};

#endif // TODO_H
