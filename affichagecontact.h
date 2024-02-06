#ifndef AFFICHAGECONTACT_H
#define AFFICHAGECONTACT_H
/*!
 * \file affichagecontact.h
 * \brief Classe associant une interaction à un tag pour la retrouver.
 * \author {Meryem.B Thomas.N}
 * \version 1.0
 */
#include <QWidget>
#include "contact.h"
#include "todo.h"
#include "todomanager.h"
#include <QComboBox>
#include <QStandardItemModel>
#include <QTranslator>

namespace Ui {
class affichageContact;
}
/*! \class Affichagecontact.
 *  \brief Classe pour afficher/modifier un contact.
 */
class affichageContact : public QWidget
{
    Q_OBJECT

public:
    explicit affichageContact(QWidget *parent = nullptr);
    ~affichageContact();
    void actualiserListe_Dates();
    QTranslator translator; /*!< Traducteur.*/
    void switchLangue(string);
    void suppLangue();

private:
    Ui::affichageContact *ui;
    Contact c;
    TodoManager tm;
    QPixmap img;
    QStandardItemModel *modelI;

private slots:
    void recContact(Contact);
    void actualiserListe();
    void majComboBox(TodoManager);
    void on_pushButton_modif_4_clicked();
    void on_pushButtonAddInteraction_clicked();

    void on_listViewInteractions_objectNameChanged(const QString &objectName);

    void on_listViewInteractions_clicked(const QModelIndex &index);

    void on_BmodifInteraction_clicked();

    void on_BsuppInteraction_clicked();

    void on_BAjoutTodo_clicked();

    void on_radioButtonAlphabetique_clicked();

    void on_radioButton_datemodif_clicked();

    void on_comboBox_activated(int index);

    void on_dateDebut_dateChanged(const QDate &date);

    void on_dateFin_dateChanged(const QDate &date);

signals:
    void envEditC(Contact);
    void envAddCInteraction(Contact);
    void envEditCInteraction(Interaction, int);
    void envSuppCInteraction(int, int);
    void envAddTodo(Todo,int, int);
};

#endif // AFFICHAGECONTACT_H
