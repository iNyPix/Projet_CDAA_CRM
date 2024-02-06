/********************************************************************************
** Form generated from reading UI file 'affichagecontact.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFFICHAGECONTACT_H
#define UI_AFFICHAGECONTACT_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_affichageContact
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_profil;
    QWidget *layoutWidget;
    QFormLayout *formLayout_4;
    QLabel *labelPhoto;
    QLabel *nomLabel_4;
    QLineEdit *nomLineEdit_4;
    QLabel *prenomLabel_4;
    QLineEdit *prenomLineEdit_4;
    QLabel *ageLabel_4;
    QSpinBox *ageSpinBox_4;
    QLabel *entrepriseLabel_4;
    QLineEdit *entrepriseLineEdit_4;
    QLabel *mailLabel_4;
    QLineEdit *mailLineEdit_4;
    QLabel *telephoneLabel_4;
    QLineEdit *telephoneLineEdit_4;
    QLabel *urlPhotoLabel;
    QLineEdit *urlPhotoLineEdit;
    QPushButton *pushButton_modif_4;
    QLabel *label_dateModif;
    QWidget *tab_interactions;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_tri;
    QRadioButton *radioButtonAlphabetique;
    QRadioButton *radioButton_datemodif;
    QDateEdit *dateDebut;
    QDateEdit *dateFin;
    QListView *listViewInteractions;
    QLineEdit *lineEditInteraction;
    QHBoxLayout *horizontalLayout_buttonI;
    QPushButton *pushButtonAddInteraction;
    QPushButton *BmodifInteraction;
    QPushButton *BsuppInteraction;
    QVBoxLayout *verticalLayout_4;
    QFormLayout *formLayout_6;
    QLabel *todoLabel_4;
    QLineEdit *todoLineEdit_4;
    QLabel *DateTodo;
    QDateEdit *dateTodoDateEdit;
    QPushButton *BAjoutTodo;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QComboBox *comboBox;
    QButtonGroup *buttonGroupTri;

    void setupUi(QWidget *affichageContact)
    {
        if (affichageContact->objectName().isEmpty())
            affichageContact->setObjectName(QString::fromUtf8("affichageContact"));
        affichageContact->resize(666, 459);
        tabWidget = new QTabWidget(affichageContact);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 651, 441));
        tabWidget->setAutoFillBackground(false);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tab_profil = new QWidget();
        tab_profil->setObjectName(QString::fromUtf8("tab_profil"));
        layoutWidget = new QWidget(tab_profil);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 631, 321));
        formLayout_4 = new QFormLayout(layoutWidget);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        labelPhoto = new QLabel(layoutWidget);
        labelPhoto->setObjectName(QString::fromUtf8("labelPhoto"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, labelPhoto);

        nomLabel_4 = new QLabel(layoutWidget);
        nomLabel_4->setObjectName(QString::fromUtf8("nomLabel_4"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, nomLabel_4);

        nomLineEdit_4 = new QLineEdit(layoutWidget);
        nomLineEdit_4->setObjectName(QString::fromUtf8("nomLineEdit_4"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, nomLineEdit_4);

        prenomLabel_4 = new QLabel(layoutWidget);
        prenomLabel_4->setObjectName(QString::fromUtf8("prenomLabel_4"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, prenomLabel_4);

        prenomLineEdit_4 = new QLineEdit(layoutWidget);
        prenomLineEdit_4->setObjectName(QString::fromUtf8("prenomLineEdit_4"));

        formLayout_4->setWidget(2, QFormLayout::FieldRole, prenomLineEdit_4);

        ageLabel_4 = new QLabel(layoutWidget);
        ageLabel_4->setObjectName(QString::fromUtf8("ageLabel_4"));

        formLayout_4->setWidget(3, QFormLayout::LabelRole, ageLabel_4);

        ageSpinBox_4 = new QSpinBox(layoutWidget);
        ageSpinBox_4->setObjectName(QString::fromUtf8("ageSpinBox_4"));

        formLayout_4->setWidget(3, QFormLayout::FieldRole, ageSpinBox_4);

        entrepriseLabel_4 = new QLabel(layoutWidget);
        entrepriseLabel_4->setObjectName(QString::fromUtf8("entrepriseLabel_4"));

        formLayout_4->setWidget(4, QFormLayout::LabelRole, entrepriseLabel_4);

        entrepriseLineEdit_4 = new QLineEdit(layoutWidget);
        entrepriseLineEdit_4->setObjectName(QString::fromUtf8("entrepriseLineEdit_4"));

        formLayout_4->setWidget(4, QFormLayout::FieldRole, entrepriseLineEdit_4);

        mailLabel_4 = new QLabel(layoutWidget);
        mailLabel_4->setObjectName(QString::fromUtf8("mailLabel_4"));

        formLayout_4->setWidget(5, QFormLayout::LabelRole, mailLabel_4);

        mailLineEdit_4 = new QLineEdit(layoutWidget);
        mailLineEdit_4->setObjectName(QString::fromUtf8("mailLineEdit_4"));

        formLayout_4->setWidget(5, QFormLayout::FieldRole, mailLineEdit_4);

        telephoneLabel_4 = new QLabel(layoutWidget);
        telephoneLabel_4->setObjectName(QString::fromUtf8("telephoneLabel_4"));

        formLayout_4->setWidget(6, QFormLayout::LabelRole, telephoneLabel_4);

        telephoneLineEdit_4 = new QLineEdit(layoutWidget);
        telephoneLineEdit_4->setObjectName(QString::fromUtf8("telephoneLineEdit_4"));

        formLayout_4->setWidget(6, QFormLayout::FieldRole, telephoneLineEdit_4);

        urlPhotoLabel = new QLabel(layoutWidget);
        urlPhotoLabel->setObjectName(QString::fromUtf8("urlPhotoLabel"));

        formLayout_4->setWidget(7, QFormLayout::LabelRole, urlPhotoLabel);

        urlPhotoLineEdit = new QLineEdit(layoutWidget);
        urlPhotoLineEdit->setObjectName(QString::fromUtf8("urlPhotoLineEdit"));

        formLayout_4->setWidget(7, QFormLayout::FieldRole, urlPhotoLineEdit);

        pushButton_modif_4 = new QPushButton(layoutWidget);
        pushButton_modif_4->setObjectName(QString::fromUtf8("pushButton_modif_4"));
        pushButton_modif_4->setEnabled(false);

        formLayout_4->setWidget(8, QFormLayout::FieldRole, pushButton_modif_4);

        label_dateModif = new QLabel(layoutWidget);
        label_dateModif->setObjectName(QString::fromUtf8("label_dateModif"));
        QFont font;
        font.setBold(false);
        font.setItalic(true);
        font.setUnderline(false);
        font.setKerning(true);
        label_dateModif->setFont(font);

        formLayout_4->setWidget(9, QFormLayout::FieldRole, label_dateModif);

        tabWidget->addTab(tab_profil, QString());
        tab_interactions = new QWidget();
        tab_interactions->setObjectName(QString::fromUtf8("tab_interactions"));
        horizontalLayoutWidget = new QWidget(tab_interactions);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 531, 401));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_tri = new QHBoxLayout();
        horizontalLayout_tri->setObjectName(QString::fromUtf8("horizontalLayout_tri"));
        horizontalLayout_tri->setContentsMargins(-1, 0, -1, -1);
        radioButtonAlphabetique = new QRadioButton(horizontalLayoutWidget);
        buttonGroupTri = new QButtonGroup(affichageContact);
        buttonGroupTri->setObjectName(QString::fromUtf8("buttonGroupTri"));
        buttonGroupTri->addButton(radioButtonAlphabetique);
        radioButtonAlphabetique->setObjectName(QString::fromUtf8("radioButtonAlphabetique"));
        radioButtonAlphabetique->setEnabled(false);

        horizontalLayout_tri->addWidget(radioButtonAlphabetique);

        radioButton_datemodif = new QRadioButton(horizontalLayoutWidget);
        buttonGroupTri->addButton(radioButton_datemodif);
        radioButton_datemodif->setObjectName(QString::fromUtf8("radioButton_datemodif"));
        radioButton_datemodif->setEnabled(false);

        horizontalLayout_tri->addWidget(radioButton_datemodif);


        verticalLayout->addLayout(horizontalLayout_tri);

        dateDebut = new QDateEdit(horizontalLayoutWidget);
        dateDebut->setObjectName(QString::fromUtf8("dateDebut"));
        dateDebut->setDate(QDate(2023, 1, 1));

        verticalLayout->addWidget(dateDebut);

        dateFin = new QDateEdit(horizontalLayoutWidget);
        dateFin->setObjectName(QString::fromUtf8("dateFin"));
        dateFin->setDate(QDate(2023, 1, 1));

        verticalLayout->addWidget(dateFin);

        listViewInteractions = new QListView(horizontalLayoutWidget);
        listViewInteractions->setObjectName(QString::fromUtf8("listViewInteractions"));

        verticalLayout->addWidget(listViewInteractions);

        lineEditInteraction = new QLineEdit(horizontalLayoutWidget);
        lineEditInteraction->setObjectName(QString::fromUtf8("lineEditInteraction"));

        verticalLayout->addWidget(lineEditInteraction);

        horizontalLayout_buttonI = new QHBoxLayout();
        horizontalLayout_buttonI->setObjectName(QString::fromUtf8("horizontalLayout_buttonI"));
        pushButtonAddInteraction = new QPushButton(horizontalLayoutWidget);
        pushButtonAddInteraction->setObjectName(QString::fromUtf8("pushButtonAddInteraction"));
        pushButtonAddInteraction->setEnabled(false);

        horizontalLayout_buttonI->addWidget(pushButtonAddInteraction);

        BmodifInteraction = new QPushButton(horizontalLayoutWidget);
        BmodifInteraction->setObjectName(QString::fromUtf8("BmodifInteraction"));
        BmodifInteraction->setEnabled(false);

        horizontalLayout_buttonI->addWidget(BmodifInteraction);

        BsuppInteraction = new QPushButton(horizontalLayoutWidget);
        BsuppInteraction->setObjectName(QString::fromUtf8("BsuppInteraction"));
        BsuppInteraction->setEnabled(false);

        horizontalLayout_buttonI->addWidget(BsuppInteraction);


        verticalLayout->addLayout(horizontalLayout_buttonI);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, -1, 0, -1);
        formLayout_6 = new QFormLayout();
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        todoLabel_4 = new QLabel(horizontalLayoutWidget);
        todoLabel_4->setObjectName(QString::fromUtf8("todoLabel_4"));

        formLayout_6->setWidget(0, QFormLayout::LabelRole, todoLabel_4);

        todoLineEdit_4 = new QLineEdit(horizontalLayoutWidget);
        todoLineEdit_4->setObjectName(QString::fromUtf8("todoLineEdit_4"));

        formLayout_6->setWidget(0, QFormLayout::FieldRole, todoLineEdit_4);

        DateTodo = new QLabel(horizontalLayoutWidget);
        DateTodo->setObjectName(QString::fromUtf8("DateTodo"));

        formLayout_6->setWidget(1, QFormLayout::LabelRole, DateTodo);

        dateTodoDateEdit = new QDateEdit(horizontalLayoutWidget);
        dateTodoDateEdit->setObjectName(QString::fromUtf8("dateTodoDateEdit"));
        dateTodoDateEdit->setDateTime(QDateTime(QDate(2023, 12, 8), QTime(19, 0, 0)));

        formLayout_6->setWidget(1, QFormLayout::FieldRole, dateTodoDateEdit);

        BAjoutTodo = new QPushButton(horizontalLayoutWidget);
        BAjoutTodo->setObjectName(QString::fromUtf8("BAjoutTodo"));
        BAjoutTodo->setEnabled(false);

        formLayout_6->setWidget(2, QFormLayout::FieldRole, BAjoutTodo);


        verticalLayout_4->addLayout(formLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFrameShape(QFrame::WinPanel);

        verticalLayout_4->addWidget(label);

        comboBox = new QComboBox(horizontalLayoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout_4->addWidget(comboBox);


        horizontalLayout->addLayout(verticalLayout_4);

        tabWidget->addTab(tab_interactions, QString());

        retranslateUi(affichageContact);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(affichageContact);
    } // setupUi

    void retranslateUi(QWidget *affichageContact)
    {
        affichageContact->setWindowTitle(QCoreApplication::translate("affichageContact", "Edition du profil", nullptr));
        labelPhoto->setText(QCoreApplication::translate("affichageContact", "Pas de photo", nullptr));
        nomLabel_4->setText(QCoreApplication::translate("affichageContact", "Nom", nullptr));
        prenomLabel_4->setText(QCoreApplication::translate("affichageContact", "Pr\303\251nom", nullptr));
        ageLabel_4->setText(QCoreApplication::translate("affichageContact", "Age", nullptr));
        entrepriseLabel_4->setText(QCoreApplication::translate("affichageContact", "Entreprise", nullptr));
        mailLabel_4->setText(QCoreApplication::translate("affichageContact", "Mail", nullptr));
        telephoneLabel_4->setText(QCoreApplication::translate("affichageContact", "T\303\251l\303\251phone", nullptr));
        urlPhotoLabel->setText(QCoreApplication::translate("affichageContact", "urlPhoto", nullptr));
        pushButton_modif_4->setText(QCoreApplication::translate("affichageContact", "Modifier", nullptr));
        label_dateModif->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_profil), QCoreApplication::translate("affichageContact", "Profil", nullptr));
        radioButtonAlphabetique->setText(QCoreApplication::translate("affichageContact", "A-Z", nullptr));
        radioButton_datemodif->setText(QCoreApplication::translate("affichageContact", "Date Modification", nullptr));
        pushButtonAddInteraction->setText(QCoreApplication::translate("affichageContact", "Ajout", nullptr));
        BmodifInteraction->setText(QCoreApplication::translate("affichageContact", "Modifier", nullptr));
        BsuppInteraction->setText(QCoreApplication::translate("affichageContact", "Supprimer", nullptr));
        todoLabel_4->setText(QCoreApplication::translate("affichageContact", "Todo", nullptr));
        DateTodo->setText(QCoreApplication::translate("affichageContact", "Date", nullptr));
        BAjoutTodo->setText(QCoreApplication::translate("affichageContact", "Ajout Todo", nullptr));
        label->setText(QCoreApplication::translate("affichageContact", "Liste todos", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_interactions), QCoreApplication::translate("affichageContact", "Interactions", nullptr));
    } // retranslateUi

};

namespace Ui {
    class affichageContact: public Ui_affichageContact {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFFICHAGECONTACT_H
