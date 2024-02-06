#ifndef TODOMANAGER_H
#define TODOMANAGER_H
/*!
 * \file todomanager.h
 * \brief Permet de gerer les todos et les associer aux interactions
 * \author {Meryem.B Thomas.N}
 * \version 1.0
 */
#include <list>
#include "todo.h"
#include "interaction.h"
#include "associationinteractiontodo.h"
/*! \class TodoManager.
 *  \brief Classe d'un gestionnaire de Todos.
 */
class TodoManager
{
private:
    list<Todo> todos; /*!< Liste des todos des contacts*/
    list<AssociationInteractionTodo> associations; /*!< Table d'association todo/interaction */

public:
    /*!
         *  \brief Constructeur.
         *
         *  Constructeur par défaut.
         *
         */
    TodoManager();
    /*!
         *  \brief Destructeur.
         *
         *  Destructeur par défaut.
         *
         */
    ~TodoManager();
    /*!
         *  \brief Ajout d'un todo.
         *
         *  Ajoute un todo à la liste
         *
         */
    void ajouterTodo(const Todo &);
    /*!
         *  \brief Supprimer un todo.
         *
         *  Supprime un todo de la liste
         *
         */
    void suppTodo(const Todo &);
    /*!
         *  \brief Association todo/interaction.
         *
         * Récupère reference et envoie à la fct d'association des pointeurs
         *
         */
    void associerTodoAInteraction(Todo &nvTodo, Interaction &interactionALier);
    /*!
         *  \brief Association  des pointeurs todo/interaction.
         *
         * Fait le lien entre les pointeurs todo et interaction
         *
         */
    void associerPointeurTodoInteraction(Todo * todo, Interaction * interaction);
    /*!
         *  \brief Dissociation todo/interaction.
         *
         * Supprime le lien entre un todo et une interaction
         *
         */
    void dissocierTodoAInteraction(Todo & todo);
    /*!
         *  \brief Liste les todos de chaques interactions d'un contact.
         *
         */
    TodoManager todoManagerByIdContact(int);
    /*!
         *  \brief Récupérer la liste des todos.
         *
         *  \return Liste des todos de tous les contacts.
         */
    list<Todo> getTodos() const;
    /*!
         *  \brief Récupérer un todo avec son id.
         *
         *  \return Un pointeur vers le todo.
         */
    Todo* getTodo(int id);
    /*!
         *  \brief Recupérer la liste des associations.
         *
         *  \return Liste des associations de tous les todos.
         */
    list<AssociationInteractionTodo> getAssociations() const;
    /*!
          *  \brief Initialise la liste des todos.
          *
          *  Permet de modifier la list contenant les todos
          */
    void setListTodo(list<Todo>);
    /*!
          *  \brief Initialise la liste des associations.
          *
          *  Permet de modifier la list contenant les associations
          */
    void setListAssociation(list<AssociationInteractionTodo>);


};

#endif // TODOMANAGER_H
