/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExport;
    QAction *actionFran_ais;
    QAction *actionAnglais;
    QAction *actionArabe;
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_rechercheTri;
    QLCDNumber *lcdNumber;
    QLineEdit *LineEditChercher;
    QRadioButton *BoutonAlpha;
    QRadioButton *BoutonDate;
    QDateEdit *DateDebut;
    QDateEdit *DateFin;
    QListView *listViewAffichage;
    QHBoxLayout *layout_boutonsContact;
    QPushButton *BNouveau;
    QPushButton *BSupprimer;
    QPushButton *pushButton_afficherListe;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuLanguage;
    QButtonGroup *BoutonTri;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1083, 658);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionExport = new QAction(MainWindow);
        actionExport->setObjectName(QString::fromUtf8("actionExport"));
        actionFran_ais = new QAction(MainWindow);
        actionFran_ais->setObjectName(QString::fromUtf8("actionFran_ais"));
        actionAnglais = new QAction(MainWindow);
        actionAnglais->setObjectName(QString::fromUtf8("actionAnglais"));
        actionArabe = new QAction(MainWindow);
        actionArabe->setObjectName(QString::fromUtf8("actionArabe"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(30, 0, 1041, 611));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_rechercheTri = new QHBoxLayout();
        horizontalLayout_rechercheTri->setObjectName(QString::fromUtf8("horizontalLayout_rechercheTri"));
        lcdNumber = new QLCDNumber(horizontalLayoutWidget_2);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setEnabled(true);
        lcdNumber->setFrameShape(QFrame::NoFrame);
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setDigitCount(5);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber->setProperty("value", QVariant(0.000000000000000));
        lcdNumber->setProperty("intValue", QVariant(0));

        horizontalLayout_rechercheTri->addWidget(lcdNumber);

        LineEditChercher = new QLineEdit(horizontalLayoutWidget_2);
        LineEditChercher->setObjectName(QString::fromUtf8("LineEditChercher"));

        horizontalLayout_rechercheTri->addWidget(LineEditChercher);

        BoutonAlpha = new QRadioButton(horizontalLayoutWidget_2);
        BoutonTri = new QButtonGroup(MainWindow);
        BoutonTri->setObjectName(QString::fromUtf8("BoutonTri"));
        BoutonTri->addButton(BoutonAlpha);
        BoutonAlpha->setObjectName(QString::fromUtf8("BoutonAlpha"));

        horizontalLayout_rechercheTri->addWidget(BoutonAlpha);

        BoutonDate = new QRadioButton(horizontalLayoutWidget_2);
        BoutonTri->addButton(BoutonDate);
        BoutonDate->setObjectName(QString::fromUtf8("BoutonDate"));

        horizontalLayout_rechercheTri->addWidget(BoutonDate);


        verticalLayout->addLayout(horizontalLayout_rechercheTri);

        DateDebut = new QDateEdit(horizontalLayoutWidget_2);
        DateDebut->setObjectName(QString::fromUtf8("DateDebut"));
        DateDebut->setDate(QDate(2023, 1, 1));

        verticalLayout->addWidget(DateDebut);

        DateFin = new QDateEdit(horizontalLayoutWidget_2);
        DateFin->setObjectName(QString::fromUtf8("DateFin"));
        DateFin->setDate(QDate(2023, 1, 1));

        verticalLayout->addWidget(DateFin);

        listViewAffichage = new QListView(horizontalLayoutWidget_2);
        listViewAffichage->setObjectName(QString::fromUtf8("listViewAffichage"));
        listViewAffichage->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(listViewAffichage);

        layout_boutonsContact = new QHBoxLayout();
        layout_boutonsContact->setObjectName(QString::fromUtf8("layout_boutonsContact"));
        BNouveau = new QPushButton(horizontalLayoutWidget_2);
        BNouveau->setObjectName(QString::fromUtf8("BNouveau"));

        layout_boutonsContact->addWidget(BNouveau);

        BSupprimer = new QPushButton(horizontalLayoutWidget_2);
        BSupprimer->setObjectName(QString::fromUtf8("BSupprimer"));

        layout_boutonsContact->addWidget(BSupprimer);


        verticalLayout->addLayout(layout_boutonsContact);

        pushButton_afficherListe = new QPushButton(horizontalLayoutWidget_2);
        pushButton_afficherListe->setObjectName(QString::fromUtf8("pushButton_afficherListe"));

        verticalLayout->addWidget(pushButton_afficherListe);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);

        verticalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout_2->addLayout(verticalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1083, 22));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuLanguage = new QMenu(menubar);
        menuLanguage->setObjectName(QString::fromUtf8("menuLanguage"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuLanguage->menuAction());
        menuFichier->addAction(actionExport);
        menuLanguage->addAction(actionFran_ais);
        menuLanguage->addAction(actionAnglais);
        menuLanguage->addAction(actionArabe);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "CRM", nullptr));
        actionExport->setText(QCoreApplication::translate("MainWindow", "Export JSON", nullptr));
        actionFran_ais->setText(QCoreApplication::translate("MainWindow", "Fran\303\247ais", nullptr));
        actionAnglais->setText(QCoreApplication::translate("MainWindow", "Anglais", nullptr));
        actionArabe->setText(QCoreApplication::translate("MainWindow", "Arabe", nullptr));
#if QT_CONFIG(accessibility)
        lcdNumber->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(whatsthis)
        LineEditChercher->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        BoutonAlpha->setText(QCoreApplication::translate("MainWindow", "A-Z", nullptr));
        BoutonDate->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        BNouveau->setText(QCoreApplication::translate("MainWindow", "Nouveau", nullptr));
        BSupprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        pushButton_afficherListe->setText(QCoreApplication::translate("MainWindow", "Ouvrir BDD", nullptr));
        menuFichier->setTitle(QCoreApplication::translate("MainWindow", "Fichier", nullptr));
        menuLanguage->setTitle(QCoreApplication::translate("MainWindow", "Langue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
