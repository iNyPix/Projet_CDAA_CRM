#ifndef WADDCONTACT_H
#define WADDCONTACT_H
/*!
 * \file waddcontact.h
 * \brief Widget ajout de contact.
 * \author {Meryem.B Thomas.N}
 * \version 1.0
 */
#include <QWidget>
#include <QObject>
#include "contact.h"
#include <QTranslator>

namespace Ui {
    class wAddContact;
}
    /*! \class wAddContact.
 *  \brief Classe pour ajouter un contact.
 */
class wAddContact : public QWidget
{
    Q_OBJECT

private:
    Ui::wAddContact *ui;
public:
    explicit wAddContact(QWidget *parent = nullptr);
    ~wAddContact();
    QTranslator translator; /*!< Traducteur.*/
    void switchLangue(string);
    void suppLangue();

private slots:
    void on_pushButton_Annuler_clicked();
    void on_pushButton_Valider_clicked();

signals:
    /*!
            *  \brief Envoyer contact.
            *
            *  Signal pour envoyer un contact.
            */
    void envContact(Contact);
    /*!
            *  \brief Fermer.
            *
            *  Signal pour fermer le widget.
            */
    void fermer();
    /*!
            *  \brief Actualiser.
            *
            *  Signal pour demander l'actualisation de la liste des contacts dans la mainWindows.
            */
    void Actualiser();

};

#endif // WADDCONTACT_H
