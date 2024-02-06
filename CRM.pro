QT += core gui
QT += sql

CONFIG += c++11
CONFIG += qt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    affichagecontact.cpp \
    associationinteractiontodo.cpp \
    associationmodificateurinteraction.cpp \
    contact.cpp \
    date.cpp \
    gestioncontacts.cpp \
    gestioninteractions.cpp \
    gestionpersonnes.cpp \
    interaction.cpp \
    main.cpp \
    mainwindow.cpp \
    modificateur.cpp \
    personne.cpp \
    querysql.cpp \
    todo.cpp \
    todomanager.cpp \
    waddcontact.cpp

HEADERS += \
    affichagecontact.h \
    associationinteractiontodo.h \
    associationmodificateurinteraction.h \
    contact.h \
    date.h \
    gestioncontacts.h \
    gestioninteractions.h \
    gestionpersonnes.h \
    interaction.h \
    mainwindow.h \
    modificateur.h \
    personne.h \
    querysql.h \
    todo.h \
    todomanager.h \
    ui_waddcontact.h \
    waddcontact.h

FORMS += \
    affichagecontact.ui \
    mainwindow.ui \
    waddcontact.ui

TRANSLATIONS += \
    translations/CRM_en_GB.ts \
    translations/CRM_ar_AE.ts
CONFIG += lrelease
CONFIG += embed_translations


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    bdd/bdd_CRM.sqlite \
    img/noimage \
    img/photo_femme.jpg \
    img/photo_femme2.jpg \
    img/photo_homme.jpg \
    translations/CRM_ar_AE.ts \
    translations/CRM_en_GB.qm

