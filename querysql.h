/*!
 * \file querysql.h
 * \brief Interagit avec la bdd.
 * \author {Meryem.B Thomas.N}
 * \version 1.0
 */
#ifndef QUERYSQL_H
#define QUERYSQL_H
/*!
 * \file querysql.h
 * \brief Classe d'interface avec une bdd.
 * \author {Meryem.B Thomas.N}
 * \version 1.0
 */
#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlRecord>
#include "contact.h"
#include "todo.h"
#include "gestioncontacts.h"
#include "associationinteractiontodo.h"



/*! \class QuerySQL.
 *  \brief Classe d'intéraction avec la bdd.
 */
class QuerySQL: public QObject
{
    Q_OBJECT
private:
    QSqlDatabase db; /*!< Base de donnée.*/
public:
    /*!
         *  \brief Constructeur.
         *
         *  Constructeur par défaut.
         */
    QuerySQL();
    /*!
         *  \brief Destructeur.
         *
         *  Destructeur de la classe.
         */
    ~QuerySQL();
    /*!
         *  \brief Connexion BDD.
         *
         *  Pour se connecter à la BDD.
         */
    void connexionBDD();
    /*!
         *  \brief Deconnexion BDD.
         *
         *  Pour se deconnecter à la BDD.
         */
    void deconnexionBDD();
    /*!
         *  \brief Conversion QString.
         *
         *  Pour convertir de string à QString.
         */
    QString stringToQS(string)const;

public slots:

    /* Fonctions CRUD Contact */
    /*!
         *  \brief Ajout contact.
         *
         *  Slot pour ajouter le contact à la BDD.
         */
    void ajoutContact(Contact );
    /*!
         *  \brief Modifie contact.
         *
         *  Slot pour modifier le contact dans la BDD.
         */
    void editContact( Contact);
    /*!
         *  \brief Supprime contact.
         *
         *  Slot pour supprimer le contact de la BDD.
         */
    void suppContact(Contact);

    /* Fonctions CRUD Interaction */
    /*!
         *  \brief Ajout interaction.
         *
         *  Slot pour ajouter une interaction à la BDD.
         */
    void ajoutInteraction(Interaction );
    /*!
         *  \brief Editer interaction.
         *
         *  Slot pour modifier une interaction de la BDD.
         */
    void editInteraction(Interaction);
    /*!
         *  \brief Supprime interaction.
         *
         *  Slot pour supprimer une interaction de la BDD.
         */
    void suppInteraction(Interaction );

    /* Fonctions CRUD Todo */
    /*!
         *  \brief Ajout todo.
         *
         *  Slot pour ajouter un todo à la BDD.
         */
    void ajoutTodo(Todo t);
    /*!
         *  \brief Editer Todo.
         *
         *  Slot pour modifier un Todo de la BDD.
         */
    void editTodo(Todo &);
    /*!
         *  \brief Supprime todo.
         *
         *  Slot pour supprimer un Todo de la BDD.
         */
    void suppTodo(Todo);
    /* Fonctions CRUD AssociationTodoInteraction */
    /*!
         *  \brief Ajout association interaction/todo.
         *
         *  Slot pour ajouter l'association à la BDD.
         */
    void ajoutAIT(int, int, int, int);
    /*!
         *  \brief editer association interaction/todo.
         *
         *  Slot pour modifier une association de la BDD.
         */
    void editAIT(AssociationInteractionTodo &);
    /*!
         *  \brief Supression association interaction/todo.
         *
         *  Slot pour supprimer l'association de la BDD.
         */
    void suppAIT(AssociationInteractionTodo );

    /* Fonctions autres */
       /*!
            *  \brief Retourne les contacts.
            *
            *  Slot pour demander de recupèrer les contacts de la BDD.
            */
       void getAllContacts();
       /*!
            *  \brief Retourne les Interactions.
            *
            *  Slot pour demander de recupèrer les interactions de la BDD.
            */
       void getAllInteractions();
       /*!
            *  \brief Retourne les Todos.
            *
            *  Slot pour demander de recupèrer les todos de la BDD.
            */
       void getAllTodos();
       /*!
            *  \brief Retourne les Association.
            *
            *  Slot pour demander de recupèrer les associations de la BDD.
            */
       void getAllAITS();

signals:
       /*!
            *  \brief Envoyer une liste de contacts.
            *
            *  Signal pour envoyer une liste des contats issu de la BDD.
            */
    void envListC(list<Contact>);
    /*!
            *  \brief Envoyer une liste d'interactions.
            *
            *  Signal pour envoyer une liste des interactions issu de la BDD.
            */
    void envListI(list<Interaction>);
    /*!
            *  \brief Envoyer une liste de todos.
            *
            *  Signal pour envoyer une liste des todos issu de la BDD.
            */
    void envListTd(list<Todo>);
    /*!
            *  \brief Envoyer une liste d'association.
            *
            *  Signal pour envoyer une liste des associations issu de la BDD.
            */
    void envListAIT(list<list<int>>);
};

#endif // QUERYSQL_H
