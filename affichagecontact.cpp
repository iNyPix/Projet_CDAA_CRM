#include "affichagecontact.h"
#include <QUrl>
#include <QImageReader>
#include <QPixmap>
#include "ui_affichagecontact.h"

affichageContact::affichageContact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::affichageContact)
{
    ui->setupUi(this);
    QVBoxLayout *centralLayout = new QVBoxLayout(this);
    centralLayout->addWidget(ui->tabWidget);
    setLayout(centralLayout);
    ui->tabWidget->setCurrentIndex(0);
    ui->tab_profil->setLayout(ui->formLayout_4);
    ui->tab_interactions->setLayout(ui->horizontalLayout);

    /* Liste interactions*/
    modelI = new QStandardItemModel(this);
    ui->listViewInteractions->setModel(modelI);
}

affichageContact::~affichageContact()
{
    delete ui;
}

void affichageContact::recContact(Contact c2)
{
    ui->pushButtonAddInteraction->setEnabled(true);
    ui->pushButton_modif_4->setEnabled(true);
    ui->radioButton_datemodif->setEnabled(true);
    ui->radioButtonAlphabetique->setEnabled(true);
    ui->comboBox->setEnabled(true);
    /* Importation informations du contact */
    this->c = c2;
    ui->nomLineEdit_4->setText(QString::fromStdString(c.getNom()));
    ui->prenomLineEdit_4->setText(QString::fromStdString(c.getPrenom()));
    ui->ageSpinBox_4->setValue(c.getAge());
    ui->entrepriseLineEdit_4->setText(QString::fromStdString(c.getEntreprise()));
    ui->mailLineEdit_4->setText(QString::fromStdString(c.getMail()));
    ui->telephoneLineEdit_4->setText(QString::fromStdString(c.getTelephone()));
    ui->urlPhotoLineEdit->setText(QString::fromStdString(c.getUrlPhoto()));
    ui->label_dateModif->setText( tr("Modifié le: ") + QString::fromStdString(c.getModification().affiche()));

    /* Récupération de l'image */
    QPixmap photo(QString::fromStdString(c.getUrlPhoto()));
    if(photo.isNull())
        photo.load("./img/noimage");
    // Redimensionnez l'image si nécessaire
    photo = photo.scaled(150, 400,Qt::KeepAspectRatio);
    ui->labelPhoto->setStyleSheet("QLabel { border: 5px solid black; padding: 2px; }");
    // Définissez l'image sur le QLabel
    ui->labelPhoto->setPixmap(photo);
    /* Liste des interactions */
    actualiserListe();
}

void affichageContact::actualiserListe()
{
    modelI->clear();
    qDebug() << "Importation des interactions du contact...";
    // Insertion des données
    for(Interaction i : c.getGestInteraction()->getList())
    {
        QStandardItem *item = new QStandardItem(QString("%1 %2").arg(i.affiche().c_str()).arg(i.getDateModif().affiche().c_str()));
        modelI->appendRow(item);
    }
}

void affichageContact::on_pushButton_modif_4_clicked()
{
    bool modif = false;
    /* Test si une information change */
    if(ui->nomLineEdit_4->text().toStdString() != c.getNom())
    {
        c.setNom(ui->nomLineEdit_4->text().toStdString());
        modif = true;
    }
    else if(ui->prenomLineEdit_4->text().toStdString() != c.getPrenom())
    {
        c.setPrenom(ui->prenomLineEdit_4->text().toStdString());
        modif = true;
    }
    else if (ui->ageSpinBox_4->value() != c.getAge())
    {
        c.setAge(ui->ageSpinBox_4->value());
        modif = true;
    }
    else if(ui->entrepriseLineEdit_4->text().toStdString() != c.getEntreprise())
    {
        c.setEntreprise(ui->entrepriseLineEdit_4->text().toStdString());
        modif = true;
    }
    else if(ui->mailLineEdit_4->text().toStdString() != c.getMail())
    {
        c.setMail(ui->mailLineEdit_4->text().toStdString());
        modif = true;
    }
    else if(ui->telephoneLineEdit_4->text().toStdString() != c.getTelephone())
    {
        c.setTelephone(ui->telephoneLineEdit_4->text().toStdString());
        modif = true;
    }
    else if (ui->urlPhotoLineEdit->text().toStdString() != c.getUrlPhoto())
    {
        c.setUrlPhoto(ui->urlPhotoLineEdit->text().toStdString());
        modif = true;
    }
    if (modif) // si une modificationn est détécté, on emet le signal
    {
        c.setModification();
        envEditC(c);
    }
}

void affichageContact::on_pushButtonAddInteraction_clicked()
{
    Interaction i(ui->lineEditInteraction->text().toStdString(),c.getId());
    c.getGestInteraction()->addInteraction(i);
    ui->lineEditInteraction->clear();
    actualiserListe();
    emit envAddCInteraction(c);
}


void affichageContact::on_listViewInteractions_objectNameChanged(const QString &objectName)
{
}


void affichageContact::on_listViewInteractions_clicked(const QModelIndex &index)
{

    ui->lineEditInteraction->setText(modelI->itemFromIndex(index)->text());
    ui->BmodifInteraction->setEnabled(true);
    ui->BsuppInteraction->setEnabled(true);
    ui->BAjoutTodo->setEnabled(true);
}


void affichageContact::on_BmodifInteraction_clicked()
{
    if(ui->listViewInteractions->currentIndex().row() != -1)
    {
        Interaction *i = c.getGestInteraction()->rechInteraction(ui->listViewInteractions->currentIndex().row()+1);
        i->setContenu(ui->lineEditInteraction->text().toStdString());
        i->setDateModif();
        ui->lineEditInteraction->clear();
        ui->label_dateModif->setText("Modifié le: " + QString::fromStdString(c.getModification().affiche()));
        actualiserListe();
        emit envEditCInteraction(*i, c.getId());
        ui->BmodifInteraction->setEnabled(false);
        ui->BsuppInteraction->setEnabled(false);
    }
}


void affichageContact::on_BsuppInteraction_clicked()
{
    QModelIndex index = ui->listViewInteractions->currentIndex();
    if(index.isValid())
    {
        Interaction *i = c.getGestInteraction()->rechInteraction(ui->listViewInteractions->currentIndex().row()+1);
        modelI->clearItemData(ui->listViewInteractions->currentIndex());
        ui->lineEditInteraction->clear();
        actualiserListe();
        emit envSuppCInteraction(i->getId(), c.getId());
    }
}


void affichageContact::on_BAjoutTodo_clicked()
{
    int idInteraction = ui->listViewInteractions->currentIndex().row()+1;
    if (idInteraction != -1)
    {
        int idContact = c.getId();
        string d = to_string(ui->dateTodoDateEdit->date().day()) + "/" + to_string(ui->dateTodoDateEdit->date().month())+ "/" + to_string(ui->dateTodoDateEdit->date().year());
        Date date_Todo(d);
        Todo td(ui->todoLineEdit_4->text().toStdString(),date_Todo);
        emit envAddTodo(td,idContact,idInteraction);
        //
        Interaction *i = c.getGestInteraction()->rechInteraction(idInteraction);
        tm.associerTodoAInteraction(td, *i);
        majComboBox(tm);
        ui->BAjoutTodo->setEnabled(false);
    }
}


void affichageContact::on_radioButtonAlphabetique_clicked()
{
    // Tri alphabétique
    modelI->sort(0);  // Trie la colonne 0 (la première colonne) par ordre alphabétique
}


void affichageContact::on_radioButton_datemodif_clicked()
{
    list<Interaction> listeInterTri = c.getGestInteraction()->getList();
    // Tri de la liste de contacts par date de création
    c.getGestInteraction()->trier_date_modification(listeInterTri);
    // Mise à jour du modèle de vue
    modelI->clear();
    // Insertion des données
    for(Interaction i : listeInterTri)
    {
        //QStandardItem *item = new QStandardItem(QString("%1 %2").arg(c.getPrenom().c_str()).arg(c.getNom().c_str()));
        QStandardItem *item = new QStandardItem(QString("%1 %2").arg(i.affiche().c_str()).arg(i.getDateModif().affiche().c_str()));
        //QStandardItem *item = new QStandardItem(QString::fromStdString(i.affiche()));
        modelI->appendRow(item);
    }
}
void affichageContact::majComboBox(TodoManager TDM)
{
    // Efface le contenu actuel de la combobox
    ui->comboBox->clear();
    qDebug() << "Importation des todos/aits du contact...";
    tm = TDM;
    ui->comboBox->addItem("");
    for(Todo td : tm.getTodos())
    {
        ui->comboBox->addItem(QString::fromStdString(td.getContenu()));
    }
}

void affichageContact::on_comboBox_activated(int index)
{
    if(index <= 0)
    {
        actualiserListe();
    }
    else
    {
        Todo td = *tm.getTodo(index);
        // Filtrer la liste de contacts en fonction des dates
        std::list<Interaction> listeInter;
        for(AssociationInteractionTodo ait : tm.getAssociations())
        {
            cout << "ID_AIT= "<< ait.getId() << " idTodo= "<< ait.getTodo().getId() << " idInteraction= "<< ait.getInteraction().getId()<< endl;
            // Comparer les dates
            if (ait.getTodo().getId() == td.getId()) {
                listeInter.push_back(ait.getInteraction());
            }
        }

        // Mise à jour du modèle de vue avec la liste filtrée
        modelI->clear();
        for(Interaction i : listeInter)
        {
            QStandardItem *item = new QStandardItem(QString("%1 %2").arg(i.affiche().c_str()).arg(i.getDateModif().affiche().c_str()));
            modelI->appendRow(item);
        }
    }
}

void affichageContact::actualiserListe_Dates()
{
    // Stocker les dates de début et de fin
    string dd = to_string(ui->dateDebut->date().day()) + "/" + to_string(ui->dateDebut->date().month())+ "/" + to_string(ui->dateDebut->date().year());

    Date dateDebut(dd);

    string df = to_string(ui->dateFin->date().day()) + "/" + to_string(ui->dateFin->date().month())+ "/" + to_string(ui->dateFin->date().year());
    Date dateFin(df);

    // Filtrer la liste de contacts en fonction des dates
    std::list<Interaction> listeInter;
    for (Interaction i : c.getGestInteraction()->getList()) {
        Date dateModif = i.getDateModif();
        // Comparer les dates
        if (dateModif >= dateDebut && dateModif <= dateFin) {
            listeInter.push_back(i);

        }
    }
    // Mise à jour du modèle de vue avec la liste filtrée
    modelI->clear();
    for(Interaction i : listeInter)
    {
        QStandardItem *item = new QStandardItem(QString("%1 %2").arg(i.affiche().c_str()).arg(i.getDateModif().affiche().c_str()));
        modelI->appendRow(item);
    }

}

void affichageContact::on_dateDebut_dateChanged(const QDate &date)
{
    actualiserListe_Dates();
}


void affichageContact::on_dateFin_dateChanged(const QDate &date)
{
    actualiserListe_Dates();
}

void affichageContact::switchLangue(string s)
{
    QCoreApplication::removeTranslator(&translator);
    if (translator.load(QString::fromStdString(s))) {  // Charger le nouveau traducteur
        QCoreApplication::installTranslator(&translator);  // Installer le nouveau traducteur
        ui->retranslateUi(this);
    }
}

void affichageContact::suppLangue()
{
    QCoreApplication::removeTranslator(&translator);
    ui->retranslateUi(this);
}

