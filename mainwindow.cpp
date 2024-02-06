#include "mainwindow.h"
#include "affichagecontact.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QFileDialog>

#include "waddcontact.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralwidget->setLayout(ui->horizontalLayout_2); // Layout principal

    /* Création du modèle de liste des contacts */
    model = new QStandardItemModel(this);
    ui->listViewAffichage->setModel(model);
    /* Widget droite : affichage contact|interactions|todos */
    ac = new affichageContact();
    ui->verticalLayout_2->addWidget(ac);

    /* Signaux SQL */
        // Demande liste des contacts
        connect(&isql,SIGNAL(envListC(list<Contact>)),this,SLOT(recListeContact(list<Contact>))); // envoie de la liste à l'application
        // Ajout d'un contact
        connect(this,SIGNAL(ouvrirWaddContact()),&wAC, SLOT(show()));
        connect(&wAC,SIGNAL(envContact(Contact)),this,SLOT(ajoutContact(Contact)));
        connect(this, SIGNAL(envContact(Contact)), &isql, SLOT(ajoutContact(Contact)));
        // Suppression d'un contact
        connect(this,SIGNAL(suppContact(Contact)),&isql,SLOT(suppContact(Contact)));
        // Edition d'un contact
        connect(this,SIGNAL(envContactEdit(Contact)),&isql,SLOT(editContact(Contact)));

        // Demande liste des interactions
        connect(&isql,SIGNAL(envListI(list<Interaction>)),this,SLOT(recListeInteraction(list<Interaction>)));
        // Ajout interaction
        connect(this,SIGNAL(envContactAddInteraction(Interaction)),&isql,SLOT(ajoutInteraction(Interaction)));
        // Edition interaction
        connect(this,SIGNAL(envContactEditInteraction(Interaction)),&isql,SLOT(editInteraction(Interaction)));
        // Suppression interaction
        connect(this,SIGNAL(envContactSuppInteraction(Interaction)),&isql,SLOT(suppInteraction(Interaction)));

        // Demande liste des todos
        connect(&isql, SIGNAL(envListTd(list<Todo>)), this, SLOT(recListeTodo(list<Todo>))); // envoie la liste des todos à l'application
        // Ajout Todo
        connect(this, SIGNAL(envAddTodo(Todo)),&isql, SLOT(ajoutTodo(Todo)));

        // Demande les associations interaction/todo
        connect(&isql, SIGNAL(envListAIT(list<list<int>>)), this, SLOT(recListeAIT(list<list<int>>)));
        // Ajout Ait
        connect(this, SIGNAL(envAddAIT(int,int,int,int)), &isql, SLOT(ajoutAIT(int,int,int,int)));

    /* Signaux Widget Affichage Contact*/
        // Contact
        connect(this,SIGNAL(envContactAffichage(Contact)),ac,SLOT(recContact(Contact))); // ouvertue de l'afficheur et reception contact
        connect(ac,SIGNAL(envEditC(Contact)),this, SLOT(editContact(Contact))); // Reception du contact modifie et envoie à l'application
        // Interactions
        connect(ac,SIGNAL(envAddCInteraction(Contact)),this,SLOT(addContactInteraction(Contact))); // Reception du contact avec interaction
        connect(ac,SIGNAL(envEditCInteraction(Interaction,int)),this,SLOT(editContactInteraction(Interaction,int))); // reception du contact avec interaction modifiée
        connect(ac,SIGNAL(envSuppCInteraction(int,int)),this,SLOT(suppContactInteraction(int,int)));
        // Todos | AIT
        connect(ac,SIGNAL(envAddTodo(Todo,int,int)),this, SLOT(addTodoAIT(Todo, int, int))); // Reception du todo avec AIT
        connect(this, SIGNAL(envTodoManager(TodoManager)), ac, SLOT(majComboBox(TodoManager))); // envoie todos et ait

    /* Signaux MainWindows */
        // Tri
        connect(ui->BoutonAlpha, SIGNAL(clicked()), this,SLOT(on_BoutonAlpha_clicked())); // clique tri ordre alphabetique
        connect(ui->BoutonDate, SIGNAL(clicked()), this, SLOT(on_BoutonDate_clicked())); // clique tri ordre par date
        // Recherche
        connect(ui->LineEditChercher, SIGNAL(textChanged(QString)), this, SLOT(on_LineEditChercher_textChanged(QString))); // recherche par nom
        connect(ui->DateDebut, SIGNAL(dateChanged(QDate)), this, SLOT(on_DateDebut_dateChanged())); // changement date debut
        connect(ui->DateFin, SIGNAL(dateChanged(QDate)), this, SLOT(on_DateFin_dateChanged())); // changement date fin
        // Export JSON
        connect(ui->actionExport, SIGNAL(triggered()), this, SLOT(on_actionExport_triggered())); // pour exporter en JSON
    isql.getAllContacts();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::debut()
{
    isql.getAllContacts();
}

void MainWindow::recListeContact(list<Contact> liste)
{
    model->clear();
    qDebug() << "Importation contacts depuis la BDD...";
    gc.setListContacts(liste);
    ui->lcdNumber->display(gc.getNbrContacts());
    // Insertion des données
    for(Contact c : gc.getListContacts())
    {
        QStandardItem *item = new QStandardItem(QString("%1 %2").arg(c.getPrenom().c_str()).arg(c.getNom().c_str()));
        model->appendRow(item);
    }
    isql.getAllInteractions();
    isql.getAllTodos();
    isql.getAllAITS();
}

void MainWindow::recListeInteraction(list<Interaction> listrecu)
{
    qDebug() << "Importation interactions depuis la BDD...";
    for(Interaction i : listrecu)
    {
        gc.getContactById(i.getIdContact())->getGestInteraction()->addInteraction(i);
    }
}

void MainWindow::ajoutContact(Contact c)
{
      gc = gc + c;
      Contact lastContact = gc.getListContacts().back();
      emit envContact(lastContact);
}

void MainWindow::editContact(Contact cM)
{
      for(auto c = gc.getListContacts().begin() ; c != gc.getListContacts().end(); ++c)
      {
        if(c->getId() == cM.getId())
        {
            qDebug() << "Contact à modifier trouvé !";
            *c = cM;
            emit envContactEdit(*c); // modification info contact
            break;
        }
      }
}

void MainWindow::addContactInteraction(Contact cM)
{
      for(auto c = gc.getListContacts().begin() ; c != gc.getListContacts().end(); ++c)
      {
        if(c->getId() == cM.getId())
        {
            qDebug() << "Contact à modifier trouvé !";
            *c = cM;
            emit envContactAddInteraction(c->getGestInteraction()->getList().back());
            break;
        }
      }
}

void MainWindow::editContactInteraction(Interaction i, int idC)
{
    Contact *c = gc.getContactById(idC);
    Interaction *inter = c->getGestInteraction()->rechInteraction(i.getId());
    inter = &i;
    emit envContactEditInteraction(*inter);
}

void MainWindow::suppContactInteraction(int idI, int idC)
{
    Contact *c = gc.getContactById(idC);
    emit envContactSuppInteraction(*c->getGestInteraction()->rechInteraction(idI));
    c->getGestInteraction()->suppInteraction(idI);
}

void MainWindow::recListeTodo(list<Todo> listTD)
{
    tm.setListTodo(listTD);
}

void MainWindow::recListeAIT(list<list<int>> reclistAIT)
{
    list<AssociationInteractionTodo> listAIT;
    for(list<int> recAIT : reclistAIT)
    {
        AssociationInteractionTodo ait;
        int idInteraction;
        list<int>::iterator it = recAIT.begin();
        if(it != recAIT.end())
        {
            ait.setId(*it);
        }
        advance(it, 1);
        if(it != recAIT.end())
        {
           ait.setTodo(tm.getTodo(*it));
        }
        advance(it, 1);
        if(it != recAIT.end())
        {
           idInteraction = *it;
        }
        advance(it, 1);
        if(it != recAIT.end())
        {
           ait.setInteraction(gc.getContactById(*it)->getGestInteraction()->rechInteraction(idInteraction));
        }
        listAIT.push_back(ait);
    }
    tm.setListAssociation(listAIT);

}


void MainWindow::addTodoAIT(Todo td, int idC, int idI)
{

    Contact *c = gc.getContactById(idC);
    Interaction *i = c->getGestInteraction()->rechInteraction(idI);
    tm.associerTodoAInteraction(td, *i);
    AssociationInteractionTodo ait = tm.getAssociations().back();
    int idAiT = ait.getId();
    int idTd = ait.getTodo().getId();
    int idi = ait.getInteraction().getId();

    emit envAddAIT(idAiT, idTd, idi, idC);
    emit envAddTodo(tm.getTodos().back());
}

void MainWindow::on_BNouveau_clicked()
{
    emit ouvrirWaddContact();
}

void MainWindow::on_pushButton_afficherListe_clicked()
{
    isql.getAllContacts();
}


void MainWindow::on_listViewAffichage_clicked(const QModelIndex &index)
{
    QStandardItem *item = model->itemFromIndex(index);
    QString prenom = item->text().section(' ',0,0);
    QString nom = item->text().section(' ',1,1);
    Contact c = gc.getContactByNameSurname(nom.toStdString(),prenom.toStdString());
    TodoManager test = tm.todoManagerByIdContact(c.getId());

    emit envTodoManager(test);
    emit envContactAffichage(c);
}
void MainWindow::on_BoutonAlpha_clicked()
{
    // Tri alphabétique
    isql.getAllContacts();
    model->sort(0);  // Trie la colonne 0 (la première colonne) par ordre alphabétique
}
void MainWindow::on_BoutonDate_clicked()
{
    isql.getAllContacts();
    std::list<Contact> listeContacts = gc.getListContacts();
    // Tri de la liste de contacts par date de création
    gc.trier_date_creation(listeContacts);

    // Mise à jour du modèle de vue
    recListeContact(listeContacts);
}
void MainWindow::on_LineEditChercher_textChanged(const QString &text)
{
    isql.getAllContacts();
    // Filtre la liste complète des contacts en fonction du texte
    std::list<Contact> listeFiltree;
    for (const Contact &c : gc.getListContacts()) {
        // Compare le texte avec le nom du contact
        QString nom = QString::fromStdString(c.getNom());
        QString entreprise = QString::fromStdString(c.getEntreprise());
        if (nom.contains(text, Qt::CaseInsensitive) || entreprise.contains(text, Qt::CaseInsensitive)) {
            listeFiltree.push_back(c);
        }
    }
    // Mise à jour du modèle de vue avec la liste filtrée
    model->clear();
    // Insertion des données
    for(Contact c : listeFiltree)
    {
        QStandardItem *item = new QStandardItem(QString("%1 %2").arg(c.getPrenom().c_str()).arg(c.getNom().c_str()));
        model->appendRow(item);
    }
}
void MainWindow::actualiserListe_Dates() {
    // Stocker les dates de début et de fin
    string dd = to_string(ui->DateDebut->date().day()) + "/" + to_string(ui->DateDebut->date().month())+ "/" + to_string(ui->DateDebut->date().year());

    Date dateDebut(dd);

    string df = to_string(ui->DateFin->date().day()) + "/" + to_string(ui->DateFin->date().month())+ "/" + to_string(ui->DateFin->date().year());
    Date dateFin(df);

    // Filtrer la liste de contacts en fonction des dates
    std::list<Contact> listeFiltree;
    for (const Contact &c : gc.getListContacts()) {
        Date dateCreation = c.getCreation();

        // Comparer les dates
        if (dateCreation >= dateDebut && dateCreation <= dateFin) {
            listeFiltree.push_back(c);
        }
    }

    // Mise à jour du modèle de vue avec la liste filtrée
    model->clear();
    for(Contact c : listeFiltree)
    {
        QStandardItem *item = new QStandardItem(QString("%1 %2").arg(c.getPrenom().c_str()).arg(c.getNom().c_str()));
        model->appendRow(item);
    }
}
void MainWindow::on_DateDebut_dateChanged()
{
    actualiserListe_Dates();
}


void MainWindow::on_DateFin_dateChanged()
{
    actualiserListe_Dates();
}

void MainWindow::on_BSupprimer_clicked()
{
    QModelIndex index = ui->listViewAffichage->currentIndex();
    if (index.isValid())
    {
        QStandardItem *item = model->itemFromIndex(index);
        QString prenom = item->text().section(' ',0,0);
        QString nom = item->text().section(' ',1,1);
        Contact c = gc.getContactByNameSurname(nom.toStdString(),prenom.toStdString());
        gc = gc - c;
        emit suppContact(c);
        isql.getAllContacts();
    }
}

/* Exporter en JSON */
void MainWindow::on_actionExport_triggered()
{
    // Le chemin du fichier JSON à partir de l'utilisateur
    QString cheminFichier = QFileDialog::getSaveFileName(this, "Export en JSON", QDir::currentPath(), "JSON Files (*.json)");

    if (!cheminFichier.isEmpty()) {
        // Ouvrir le fichier pour écriture
        QFile fichierJSON(cheminFichier);
        if (!fichierJSON.open(QIODevice::WriteOnly)) {
            qDebug() << "Erreur lors de l'ouverture du fichier JSON : " << fichierJSON.errorString();
        }

        QJsonArray listeContacts;

        for ( Contact &c : gc.getListContacts()) {
            QJsonObject infos_contact;
            infos_contact.insert("(a)- Nom", QString::fromStdString(c.getNom()));
            infos_contact.insert("(b)- Prenom", QString::fromStdString(c.getPrenom()));
            infos_contact.insert("(c)- Age", c.getAge());
            infos_contact.insert("(d)- Entreprise", QString::fromStdString(c.getEntreprise()));
            infos_contact.insert("(e)- mail", QString::fromStdString(c.getMail()));
            infos_contact.insert("(f)- Telephone", QString::fromStdString(c.getTelephone()));
            infos_contact.insert("(g)- UrlPhoto", QString::fromStdString(c.getUrlPhoto()));
            listeContacts.append(infos_contact);
            for(Interaction &i : c.getGestInteraction()->getList())
            {
               QJsonObject infos_interaction;
                infos_interaction.insert("(a)- Id", i.getId());
                infos_interaction.insert("(b)- Id contact", i.getIdContact());
                infos_interaction.insert("(c)- Contenu", QString::fromStdString(i.getContenu()));
                infos_interaction.insert("(d)- Creation", QString::fromStdString(i.getDate().affiche()));
                infos_interaction.insert("(e)- Modification", QString::fromStdString(i.getDateModif().affiche()));
                listeContacts.append(infos_interaction);
            }
        }

        QJsonDocument Document(listeContacts);
        // Convertir le document JSON en une chaîne JSON
        QByteArray donneesJSON = Document.toJson(QJsonDocument::Indented);

        // Écrire la chaîne JSON dans le fichier
        fichierJSON.write(donneesJSON);
        // Fermer le fichier
        fichierJSON.close();
        qDebug() << "Export JSON réussi";
    }
}

void MainWindow::on_actionFran_ais_triggered()
{
    wAC.suppLangue();
    ac->suppLangue();
    QCoreApplication::removeTranslator(&translator);
    ui->retranslateUi(this);
}

void MainWindow::on_actionAnglais_triggered()
{
    QCoreApplication::removeTranslator(&translator);
    if (translator.load("./translations/CRM_en_GB.qm")) {  // Charger le nouveau traducteur
        QCoreApplication::installTranslator(&translator);  // Installer le nouveau traducteur
        ui->retranslateUi(this);
        ac->switchLangue("./translations/CRM_en_GB.qm");
        wAC.switchLangue("./translations/CRM_en_GB.qm");
    }


}


void MainWindow::on_actionArabe_triggered()
{
    QCoreApplication::removeTranslator(&translator);
    if (translator.load("./translations/CRM_ar_AE.qm")) {  // Charger le nouveau traducteur
        QCoreApplication::installTranslator(&translator);  // Installer le nouveau traducteur
        ui->retranslateUi(this);
        ac->switchLangue("./translations/CRM_ar_AE.qm");
        wAC.switchLangue("./translations/CRM_ar_AE.qm");
    }
}

