#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/*!
 * \file mainwindows.h
 * \brief Fenêtre principal de l'application.
 * \author {Meryem.B Thomas.N}
 * \version 1.0
 */
#include <QMainWindow>
#include <QStringListModel>
#include <QStandardItemModel>
#include "contact.h"
#include "gestioncontacts.h"
#include "todomanager.h"
#include "querysql.h"
#include "waddcontact.h"
#include "affichagecontact.h"
#include <QTranslator>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
/*! \class MainWindows.
 *  \brief Classe de l'application.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    GestionContacts gc; /*!< Gestionnaire des contacts et leurs interactions.*/
    TodoManager tm; /*!< Gestionnaire des todos + associations.*/
    QuerySQL isql; /*!< Executeur de requête SQL vers la BDD.*/
    wAddContact wAC; /*!< Widget d'ajout de contact.*/
    affichageContact *ac; /*!< Widget pour afficher les informations d'un contact.*/
    QStandardItemModel *model; /*!< Modèle pour lister tous les contacts.*/
    QTranslator translator; /*!< Traducteur.*/
public:
    /*!
        *  \brief Constructeur.
        *
        *  Constructeur par défaut.
    */
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void debut();
private slots:
    void on_listViewAffichage_clicked(const QModelIndex &index);
    // Contacts
    /*!
         *  \brief Reception contacts.
         *
         *  Slot pour réceptionner les contacts.
         *
         *  \param list<Contact> : liste d'objet Contact.
         */
    void recListeContact(list<Contact>);
    /*!
         *  \brief Edition de contact.
         *
         *  Slot pour réceptionner le contact à modifier.
         *
         *  \param Contact : un contact.
         */
    void editContact(Contact);
    /*!
         *  \brief Ajout de contact.
         *
         *  Slot pour réceptionner le contact à ajouter.
         *
         *  \param Contact : un contact.
         */
    void ajoutContact(Contact);

    // Interactions
    /*!
         *  \brief Reception interactions.
         *
         *  Slot pour réceptionner les interactions.
         *
         *  \param list<Interaction> : liste d'objet Interaction.
         */
    void recListeInteraction(list<Interaction>);
    /*!
         *  \brief Ajout interactions.
         *
         *  Slot pour ajouter les interactions.
         *
         *  \param Contact : un contact avec ses interactions.
         */
    void addContactInteraction(Contact);
    /*!
         *  \brief Modification interaction.
         *
         *  Slot pour modifier une interaction.
         *
         *  \param Interaction : une interaction.
         *  \param Integer : id du contact.
         */
    void editContactInteraction(Interaction, int);
    /*!
         *  \brief Suppression interaction.
         *
         *  Slot pour supprimer une interaction.
         *
         *  \param Integer : id de l'interaction.
         *  \param Integer : id du contact.
         */
    void suppContactInteraction(int, int);


    // Todo/AIT
    /*!
         *  \brief Reception todo.
         *
         *  Slot pour réceptionner les todos.
         *
         *  \param list<Todo> : liste d'objet Todo.
         */
    void recListeTodo(list<Todo>);
    /*!
         *  \brief Reception Association.
         *
         *  Slot pour réceptionner les associations.
         *
         *  \param list<AssociationInteractionTodo> : liste d'objet AssociationInteractionTodo.
         */
    void recListeAIT(list<list<int>>);
    /*!
         *  \brief Ajout todo et association.
         *
         *  Slot pour ajouter un todo et l'association à une interaction.
         *
         *  \param Todo : un todo.
         *  \param Integer : id du contact.
         *  \param Integer : id de l'interaction.
         */
    void addTodoAIT(Todo, int, int);


    void on_BNouveau_clicked();
    void on_pushButton_afficherListe_clicked();
    void on_BoutonAlpha_clicked();
    void on_BoutonDate_clicked();
    void on_LineEditChercher_textChanged(const QString &arg1);
    void actualiserListe_Dates();
    void on_DateDebut_dateChanged();
    void on_DateFin_dateChanged();
    void on_actionExport_triggered();
    void on_BSupprimer_clicked();

    void on_actionFran_ais_triggered();

    void on_actionAnglais_triggered();

    void on_actionArabe_triggered();

signals:
    // Widget ajout contact
    void envContactAffichage(Contact);
    void ouvrirWaddContact();
    // Contacts
    void envContact(Contact);
    void envContactEdit(Contact);
    void suppContact(Contact);
    // Interactions
    void envContactAddInteraction(Interaction);
    void envContactEditInteraction(Interaction);
    void envContactSuppInteraction(Interaction);
    // Todo/AIT
    void envAddAIT(int,int, int, int);
    void envAddTodo(Todo);

    void envTodoManager(TodoManager);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
