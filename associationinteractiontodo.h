#ifndef ASSOCIATIONINTERACTIONTODO_H
#define ASSOCIATIONINTERACTIONTODO_H
/*!
 * \file associationinteractiontodo.h
 * \brief Classe associant une interaction à un tag pour la retrouver.
 * \author {Meryem.B Thomas.N}
 * \version 1.0
 */
#include "todo.h"
#include "interaction.h"
/*! \class AssociationInteractionTodo.
 *  \brief Classe associant une interaction à un todo.
 */
class AssociationInteractionTodo
{
private:
    int idAIT;
    Todo *todo;/*!< Todo à lier à l'interaction.*/
    Interaction *interaction;/*!< Interaction à lier au todo.*/
    
public:
    /*!
         *  \brief Constructeur.
         *
         *  Constructeur par défaut.
         *
         */
    AssociationInteractionTodo(/* args */);
    /*!
         *  \brief Constructeur.
         *
         *  Constructeur inversé.
         *
         */
    AssociationInteractionTodo(Interaction *, Todo *);
    /*!
         *  \brief Destructeur.
         *
         *  Destructeur par défaut.
         *
         */
    ~AssociationInteractionTodo();
    /*!
         *  \brief Definir id.
         *
         *  Permet de choisir l'id.
         */
    void setId(int);
    /*!
         *  \brief Liaison du todo.
         *
         *  Permet de choisir le todo à lier.
         */
    void setTodo(Todo *);
    /*!
         *  \brief Liaison de l'interaction.
         *
         *  Permet de choisir l'interaction à lier.
         */
    void setInteraction(Interaction *);
    /*!
         *  \brief Recuperer id.
         *
         *  \return Permet de connaitre l'id.
         */
    int getId();
    /*!
         *  \brief Retrouve le todo.
         *
         *  \return Le todo lié à une interaction.
         */
    Todo getTodo();
    /*!
         *  \brief Retrouve l'interaction.
         *
         *  \return L'interaction lié à un todo.
         */
    Interaction getInteraction();
    /*!
         *  \brief Surcharge de l'opérateur d'affichage.
         *
         *  \return Flux ostream (cout).
         */
    friend ostream& operator<<(ostream &, const AssociationInteractionTodo &);
};


#endif // ASSOCIATIONINTERACTIONTODO_H
