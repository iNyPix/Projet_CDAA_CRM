#include "waddcontact.h"
#include "ui_waddcontact.h"

wAddContact::wAddContact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wAddContact)
{
    ui->setupUi(this);
    QObject::connect(this,SIGNAL(fermer()),this,SLOT(close()));
}

wAddContact::~wAddContact()
{
    delete ui;
}

void wAddContact::on_pushButton_Annuler_clicked()
{
    emit fermer();
}

void wAddContact::on_pushButton_Valider_clicked()
{
    Contact c(ui->nomLineEdit->text().toStdString(),
              ui->prenomLineEdit->text().toStdString(),
              ui->ageLineEdit->text().toInt(),
              ui->entrepriseLineEdit->text().toStdString(),
              ui->mailLineEdit->text().toStdString(),
              ui->telephoneLineEdit->text().toStdString(),
              ui->urlPhotoLineEdit->text().toStdString());

    emit envContact(c);
    emit fermer();
    emit Actualiser();
    // Effacez le contenu de tous les champs
    ui->nomLineEdit->clear();
    ui->prenomLineEdit->clear();
    ui->ageLineEdit->clear();
    ui->entrepriseLineEdit->clear();
    ui->mailLineEdit->clear();
    ui->telephoneLineEdit->clear();
    ui->urlPhotoLineEdit->clear();
}

void wAddContact::switchLangue(string s)
{
    QCoreApplication::removeTranslator(&translator);
    if (translator.load(QString::fromStdString(s))) {  // Charger le nouveau traducteur
        QCoreApplication::installTranslator(&translator);  // Installer le nouveau traducteur
        ui->retranslateUi(this);
    }
}
void wAddContact::suppLangue()
{
    QCoreApplication::removeTranslator(&translator);
    ui->retranslateUi(this);
}

