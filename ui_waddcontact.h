/********************************************************************************
** Form generated from reading UI file 'waddcontact.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WADDCONTACT_H
#define UI_WADDCONTACT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wAddContact
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *mainLayout;
    QLabel *nomLabel;
    QLineEdit *nomLineEdit;
    QLabel *prenomLabel;
    QLineEdit *prenomLineEdit;
    QLabel *ageLabel;
    QLineEdit *ageLineEdit;
    QLabel *entrepriseLabel;
    QLineEdit *entrepriseLineEdit;
    QLabel *mailLabel;
    QLineEdit *mailLineEdit;
    QLabel *telephoneLabel;
    QLineEdit *telephoneLineEdit;
    QLabel *urlPhotoLabel;
    QLineEdit *urlPhotoLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_Annuler;
    QPushButton *pushButton_Valider;

    void setupUi(QWidget *wAddContact)
    {
        if (wAddContact->objectName().isEmpty())
            wAddContact->setObjectName(QString::fromUtf8("wAddContact"));
        wAddContact->resize(729, 289);
        verticalLayoutWidget = new QWidget(wAddContact);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 721, 283));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        mainLayout = new QFormLayout();
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        nomLabel = new QLabel(verticalLayoutWidget);
        nomLabel->setObjectName(QString::fromUtf8("nomLabel"));

        mainLayout->setWidget(0, QFormLayout::LabelRole, nomLabel);

        nomLineEdit = new QLineEdit(verticalLayoutWidget);
        nomLineEdit->setObjectName(QString::fromUtf8("nomLineEdit"));

        mainLayout->setWidget(0, QFormLayout::FieldRole, nomLineEdit);

        prenomLabel = new QLabel(verticalLayoutWidget);
        prenomLabel->setObjectName(QString::fromUtf8("prenomLabel"));

        mainLayout->setWidget(1, QFormLayout::LabelRole, prenomLabel);

        prenomLineEdit = new QLineEdit(verticalLayoutWidget);
        prenomLineEdit->setObjectName(QString::fromUtf8("prenomLineEdit"));

        mainLayout->setWidget(1, QFormLayout::FieldRole, prenomLineEdit);

        ageLabel = new QLabel(verticalLayoutWidget);
        ageLabel->setObjectName(QString::fromUtf8("ageLabel"));

        mainLayout->setWidget(2, QFormLayout::LabelRole, ageLabel);

        ageLineEdit = new QLineEdit(verticalLayoutWidget);
        ageLineEdit->setObjectName(QString::fromUtf8("ageLineEdit"));

        mainLayout->setWidget(2, QFormLayout::FieldRole, ageLineEdit);

        entrepriseLabel = new QLabel(verticalLayoutWidget);
        entrepriseLabel->setObjectName(QString::fromUtf8("entrepriseLabel"));

        mainLayout->setWidget(3, QFormLayout::LabelRole, entrepriseLabel);

        entrepriseLineEdit = new QLineEdit(verticalLayoutWidget);
        entrepriseLineEdit->setObjectName(QString::fromUtf8("entrepriseLineEdit"));

        mainLayout->setWidget(3, QFormLayout::FieldRole, entrepriseLineEdit);

        mailLabel = new QLabel(verticalLayoutWidget);
        mailLabel->setObjectName(QString::fromUtf8("mailLabel"));

        mainLayout->setWidget(4, QFormLayout::LabelRole, mailLabel);

        mailLineEdit = new QLineEdit(verticalLayoutWidget);
        mailLineEdit->setObjectName(QString::fromUtf8("mailLineEdit"));

        mainLayout->setWidget(4, QFormLayout::FieldRole, mailLineEdit);

        telephoneLabel = new QLabel(verticalLayoutWidget);
        telephoneLabel->setObjectName(QString::fromUtf8("telephoneLabel"));

        mainLayout->setWidget(5, QFormLayout::LabelRole, telephoneLabel);

        telephoneLineEdit = new QLineEdit(verticalLayoutWidget);
        telephoneLineEdit->setObjectName(QString::fromUtf8("telephoneLineEdit"));

        mainLayout->setWidget(5, QFormLayout::FieldRole, telephoneLineEdit);

        urlPhotoLabel = new QLabel(verticalLayoutWidget);
        urlPhotoLabel->setObjectName(QString::fromUtf8("urlPhotoLabel"));

        mainLayout->setWidget(6, QFormLayout::LabelRole, urlPhotoLabel);

        urlPhotoLineEdit = new QLineEdit(verticalLayoutWidget);
        urlPhotoLineEdit->setObjectName(QString::fromUtf8("urlPhotoLineEdit"));

        mainLayout->setWidget(6, QFormLayout::FieldRole, urlPhotoLineEdit);


        verticalLayout->addLayout(mainLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout_4->setContentsMargins(0, 0, -1, -1);
        pushButton_Annuler = new QPushButton(verticalLayoutWidget);
        pushButton_Annuler->setObjectName(QString::fromUtf8("pushButton_Annuler"));

        horizontalLayout_4->addWidget(pushButton_Annuler);

        pushButton_Valider = new QPushButton(verticalLayoutWidget);
        pushButton_Valider->setObjectName(QString::fromUtf8("pushButton_Valider"));

        horizontalLayout_4->addWidget(pushButton_Valider);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(wAddContact);

        QMetaObject::connectSlotsByName(wAddContact);
    } // setupUi

    void retranslateUi(QWidget *wAddContact)
    {
        wAddContact->setWindowTitle(QCoreApplication::translate("wAddContact", "Ajouter un contact", nullptr));
        nomLabel->setText(QCoreApplication::translate("wAddContact", "Nom", nullptr));
        prenomLabel->setText(QCoreApplication::translate("wAddContact", "Prenom", nullptr));
        ageLabel->setText(QCoreApplication::translate("wAddContact", "Age", nullptr));
        entrepriseLabel->setText(QCoreApplication::translate("wAddContact", "Entreprise", nullptr));
        mailLabel->setText(QCoreApplication::translate("wAddContact", "Mail", nullptr));
        telephoneLabel->setText(QCoreApplication::translate("wAddContact", "Telephone", nullptr));
        urlPhotoLabel->setText(QCoreApplication::translate("wAddContact", "urlPhoto", nullptr));
        pushButton_Annuler->setText(QCoreApplication::translate("wAddContact", "Annuler", nullptr));
        pushButton_Valider->setText(QCoreApplication::translate("wAddContact", "Valider", nullptr));
    } // retranslateUi

};

namespace Ui {
    class wAddContact: public Ui_wAddContact {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WADDCONTACT_H
