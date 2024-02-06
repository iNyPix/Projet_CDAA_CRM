#include "querysql.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
 #include <QSqlError>

QuerySQL::QuerySQL()
{
    connexionBDD();
}

QuerySQL::~QuerySQL(){}

void QuerySQL::connexionBDD()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./bdd/bdd_CRM.sqlite");
    if(!db.open())
    {
        qDebug() << "SQL --> Impossible de se connecter à la BDD !";
    }
    else
        qDebug() << "SQL --> Connection réussite à la BDD !";
}
void QuerySQL::deconnexionBDD()
{
    if(db.isOpen())
        db.close();
}
QString QuerySQL::stringToQS(string str)const
{
    return QString::fromStdString(str);
}
void QuerySQL::ajoutContact(Contact c)
{
    cout << "SQL <-- Tentative d'ajout du Contact" << c.getId() << " à la bdd..." << endl;
    QSqlQuery query;
    query.prepare("INSERT INTO Contact(idContact, nom, prenom, age, entreprise, mail, telephone, urlPhoto, creation, modification) VALUES (:i, :n, :p, :a, :e, :m, :t, :u, :d, :mo)");
    query.bindValue(":i",c.getId());
    query.bindValue(":n",stringToQS(c.getNom()));
    query.bindValue(":p",stringToQS(c.getPrenom()));
    query.bindValue(":a",c.getAge());
    query.bindValue(":e",stringToQS(c.getEntreprise()));
    query.bindValue(":m",stringToQS(c.getMail()));
    query.bindValue(":t",stringToQS(c.getTelephone()));
    query.bindValue(":u",stringToQS(c.getUrlPhoto()));
    query.bindValue(":d",stringToQS(c.getCreation().affiche()));
    query.bindValue(":mo",stringToQS(c.getModification().affiche()));
    if (!query.exec())
    {
        qDebug() << "SQL --> Erreur à l'ajout dans contact";
        qDebug() << "SQL --> Erreur SQL : " << query.lastError().text();
    }
    else
        qDebug() << "SQL --> Ajout contacte réussite !";
}

void QuerySQL::suppContact(Contact c)
{
    cout << "SQL <-- Tentative de suppression du Contact " << c.getId() << " de la bdd..." << endl;
        QSqlQuery queryContact;
        queryContact.prepare("DELETE FROM Contact WHERE idContact =:i ");
        queryContact.bindValue(":i",c.getId());

        if (!queryContact.exec())
        {
            qDebug() << "SQL --> Erreur à la suppression";
            qDebug() << "SQL --> Erreur SQL : " << queryContact.lastError().text();
        }
        else
            qDebug() << "SQL --> Suppression contact réussite !";
}
void QuerySQL::editContact(Contact oldC)
{
        cout << "SQL <-- Tentative d'edition du Contact " << oldC.getId() << " de la bdd..." << endl;
        QSqlQuery query;
        query.prepare("UPDATE Contact SET nom=:newn,prenom=:newp, age=:newa, entreprise=:newe, mail=:newm, telephone=:newt, urlPhoto=:newu, creation=:newd, modification=:newmo WHERE idContact=:i");
        query.bindValue(":i",oldC.getId());

        //query.bindValue(":newi",oldC.getId());
        query.bindValue(":newn",stringToQS(oldC.getNom()));
        query.bindValue(":newp",stringToQS(oldC.getPrenom()));
        query.bindValue(":newa",oldC.getAge());
        query.bindValue(":newe",stringToQS(oldC.getEntreprise()));
        query.bindValue(":newm",stringToQS(oldC.getMail()));
        query.bindValue(":newt",stringToQS(oldC.getTelephone()));
        query.bindValue(":newu",stringToQS(oldC.getUrlPhoto()));
        query.bindValue(":newd",stringToQS(oldC.getCreation().affiche()));
        query.bindValue(":newmo",stringToQS(oldC.getModification().affiche()));
        if (!query.exec())
        {
                qDebug() << "SQL --> Erreur à la mise à jour";
            qDebug() << "SQL --> Erreur SQL : " << query.lastError().text();
        }
        else
            qDebug() << "SQL --> Màj contact réussite !";
}

void QuerySQL::ajoutInteraction(Interaction i)
{
    cout << "SQL <-- Tentative d'ajout d'une interaction " << i.getId() << " à la bdd..." << endl;
    QSqlQuery query;
    query.prepare("INSERT INTO Interaction(idInteraction,idContact, date, contenu, modification) VALUES (:ii,:ic, :d, :c, :m)");
    query.bindValue(":ii",i.getId());
    query.bindValue(":ic",i.getIdContact());
    query.bindValue(":d",stringToQS(i.getDate().affiche()));
    query.bindValue(":c",stringToQS(i.getContenu()));
    query.bindValue(":m",stringToQS(i.getDateModif().affiche()));
    if (!query.exec())
    {
        qDebug() << "SQL --> Erreur à l'ajout d'une interaction";
            qDebug() << "SQL --> Erreur SQL : " << query.lastError().text();
    }
    else
        qDebug() << "SQL --> Ajout interaction réussite !";
}

void QuerySQL::editInteraction(Interaction oldI)
{
    cout << "SQL <-- Tentative d'edition d'une interaction " << oldI.getId() << " de la bdd..." << endl;
    QSqlQuery query;
    query.prepare("UPDATE Interaction SET date=:newd, contenu=:newc, modification=:newm WHERE idInteraction=:ii AND idContact=:ic");
    query.bindValue(":ii",oldI.getId());
    query.bindValue(":ic",oldI.getIdContact());

    query.bindValue(":newd",stringToQS(oldI.getDate().affiche()));
    query.bindValue(":newc",stringToQS(oldI.getContenu()));
    query.bindValue(":newm",stringToQS(oldI.getDateModif().affiche()));

    if (!query.exec())
    {
        qDebug() << "SQL --> Erreur à la modificationn d'une interaction";
            qDebug() << "SQL --> Erreur SQL : " << query.lastError().text();
    }
    else
        qDebug() << "SQL --> Modification d'interaction réussite !";
}

void QuerySQL::suppInteraction(Interaction i)
{
    cout << "SQL <-- Tentative de suppression d'une interaction " << i.getId() << "  de la bdd..." << endl;
    QSqlQuery query;
    query.prepare("DELETE FROM Interaction WHERE idInteraction=:ii ");
    query.bindValue(":ii",i.getId());
    if (!query.exec())
    {
        qDebug() << "SQL --> Erreur à la suppression";
        qDebug() << "SQL --> Erreur SQL : " << query.lastError().text();
    }
    else
        qDebug() << "SQL --> Suppression interaction réussite !";
}

void QuerySQL::ajoutTodo(Todo td)
{
    cout << "SQL <-- Tentative d'ajout d'un todo " << td.getId() << " à la bdd..." << endl;
    QSqlQuery query;
    query.prepare("INSERT INTO Todo(idTodo,contenu,date) VALUES (:itd,:c,:d)");
    query.bindValue(":itd",td.getId());
    query.bindValue(":c",stringToQS(td.getContenu()));
    query.bindValue(":d",stringToQS(td.getDate().affiche()));
    if (!query.exec())
    {
        qDebug() << "SQL --> Erreur à l'ajout d'une interaction";
            qDebug() << "SQL --> Erreur SQL : " << query.lastError().text();
    }
    else
        qDebug() << "SQL --> Ajout interaction réussite !";
}

void QuerySQL::editTodo(Todo &oldTd)
{
    cout << "SQL <-- Tentative d'edition d'un todo " << oldTd.getId() << " de la bdd..." << endl;
    QSqlQuery query;
    query.prepare("UPDATE Todo SET contenu=:newc, date=:newd WHERE idTodo=:itd");
    query.bindValue(":itd",oldTd.getId());
    query.bindValue(":newc",stringToQS(oldTd.getContenu()));
    query.bindValue(":newd",stringToQS(oldTd.getDate().affiche()));


    if (!query.exec())
    {
        qDebug() << "SQL --> Erreur à la modificationn d'un Todo";
            qDebug() << "SQL --> Erreur SQL : " << query.lastError().text();
    }
    else
        qDebug() << "SQL --> Modification Todo réussite !";
}

void QuerySQL::suppTodo(Todo td)
{
    cout << "SQL <-- Tentative de suppression d'un todo " << td.getId() << " de la bdd..." << endl;
    QSqlQuery query;
    query.prepare("DELETE FROM Todo WHERE idTodo=:itd AND contenu=:c AND date=:d ");
    query.bindValue(":itd",td.getId());
    query.bindValue(":c",stringToQS(td.getContenu()));
    query.bindValue(":d",stringToQS(td.getDate().affiche()));
    if (!query.exec())
    {
        qDebug() << "SQL --> Erreur à la suppression";
        qDebug() << "SQL --> Erreur SQL : " << query.lastError().text();
    }
    else
        qDebug() << "SQL --> Suppression Todo réussite !";
}

void QuerySQL::ajoutAIT(int idAiT,int idTd,int idi,int idC)
{
    cout << "SQL <-- Tentative d'ajout d'une association " << idAiT << " à la bdd..." << endl;
    QSqlQuery query;
    query.prepare("INSERT INTO AssociationInteractionTodo(idAIT,todo, interaction, idContact) VALUES (:iait,:td,:i,:ic)");
    query.bindValue(":iait",idAiT);
    query.bindValue(":td", idTd);
    query.bindValue(":i",idi);
    query.bindValue(":ic",idC);
    if (!query.exec())
    {
        qDebug() << "SQL --> Erreur à l'ajout d'une AssociationInteractionTodo";
        qDebug() << "SQL --> Erreur SQL : " << query.lastError().text();
    }
    else
        qDebug() << "SQL --> Ajout AssociationInteractionTodo réussite !";
}

void QuerySQL::editAIT(AssociationInteractionTodo &oldAIT)
{
    cout << "SQL <-- Tentative d'edition d'une association " << oldAIT.getId() << " de la bdd..." << endl;
    QSqlQuery query;
    query.prepare("UPDATE AssociationInteractionTodo SET todo=:newtd, interaction=:newi WHERE idAIT=:iait");
    query.bindValue(":iait", oldAIT.getId());

    query.bindValue("newtd", oldAIT.getTodo().getId());
    query.bindValue("newi", oldAIT.getInteraction().getId());

    if (!query.exec())
    {
        qDebug() << "SQL --> Erreur à la modificationn d'une AssociationInteractionTodo";
            qDebug() << "SQL --> Erreur SQL : " << query.lastError().text();
    }
    else
        qDebug() << "SQL --> Modification AssociationInteractionTodo réussite !";
}

void QuerySQL::suppAIT(AssociationInteractionTodo ait)
{
    cout << "SQL <-- Tentative de suppresion d'une association " << ait.getId() << " de la bdd..." << endl;
    QSqlQuery query;
    query.prepare("DELETE FROM AssociationInteractionTodo WHERE idAIT=:iait AND todo=:td AND interaction=:i AND idContact=: ic");
    query.bindValue(":iait",ait.getId());
    query.bindValue(":td",ait.getTodo().getId());
    query.bindValue(":i",ait.getInteraction().getId());
    query.bindValue(":ic",ait.getInteraction().getIdContact());
    if (!query.exec())
    {
        qDebug() << "SQL --> Erreur à la suppression";
        qDebug() << "SQL --> Erreur SQL : " << query.lastError().text();
    }
    else
        qDebug() << "SQL --> Suppression AssociationInteractionTodo réussite !";
}

void QuerySQL::getAllContacts()
{
    cout << "SQL <-- Tentative de récupération des contacts de la bdd..." << endl;
    QSqlQuery query;
    query.prepare("SELECT idContact, nom, prenom, age, entreprise, mail,telephone, urlPhoto, creation, modification FROM Contact");
    if (!query.exec())
    {
        qDebug() << "SQL --> Erreur pour récupérer les contacts de la BDD";
        qDebug() << "SQL --> Erreur SQL : " << query.lastError().text();
    }
    else
    {
        qDebug() << "SQL --> Récupération réussie !";
        Contact c;
        list<Contact> list;
        while (query.next()) {
            QString r = query.value(0).toString(); // récupère id
            c.setId(r.toInt());
            r = query.value(1).toString(); // récupère nom
            c.setNom(r.toStdString());
            r = query.value(2).toString(); // récupère prenom
            c.setPrenom(r.toStdString());
            r = query.value(3).toString(); // récupère age
            c.setAge(r.toInt());
            r = query.value(4).toString(); // récupère entreprise
            c.setEntreprise(r.toStdString());
            r = query.value(5).toString(); // récupère mail
            c.setMail(r.toStdString());
            r = query.value(6).toString(); // récupère telephone
            c.setTelephone(r.toStdString());
            r = query.value(7).toString(); // récupère url
            c.setUrlPhoto(r.toStdString());
            r = query.value(8).toString(); // récupère date
            Date d(r.toStdString());
            c.setCreation(d);
            r = query.value(9).toString(); // récupère date
            Date d2(r.toStdString());
            c.setModification(d2);
            list.push_back(c);
        }
        emit envListC(list);
    }
}

void QuerySQL::getAllInteractions()
{
    cout << "SQL <-- Tentative de récupération des intéractions de la bdd..." << endl;
    QSqlQuery query;
    query.prepare("SELECT idInteraction,idContact, date, contenu, modification FROM Interaction");
    if (!query.exec())
    {
        qDebug() << "SQL --> Erreur pour récupérer les interactions de la BDD";
            qDebug() << "SQL --> Erreur SQL : " << query.lastError().text();
    }
    else
    {
        qDebug() << "SQL --> Récupération réussie !";
        Interaction i;
        list<Interaction> listI;
        while (query.next()) {
            QString r = query.value(0).toString(); // récupère id
            i.setId(r.toInt());

            r = query.value(1).toString(); // récupère idContact
            i.setIdContact(r.toInt());

            r = query.value(2).toString(); // récupère Date
            Date d(r.toStdString());
            i.setDate(d);

            r = query.value(3).toString(); // récupère Contenu
            i.setContenu(r.toStdString());

            r = query.value(4).toString(); // récupère Date
            Date modif(r.toStdString());
            i.setDateModifD(modif);
            listI.push_back(i);
        }
        emit envListI(listI);
    }
}

void QuerySQL::getAllTodos()
{
    cout << "SQL <-- Tentative de récupération des todos de la bdd..." << endl;
    QSqlQuery query;
    query.prepare("SELECT idTodo, contenu, date FROM Todo");
    if (!query.exec())
    {
        qDebug() << "SQL --> Erreur pour récupérer les todos de la BDD";
            qDebug() << "SQL --> Erreur SQL : " << query.lastError().text();
    }
    else
    {
        qDebug() << "SQL --> Récupération réussie !";
        Todo td;
        list<Todo> listTd;
        while (query.next()) {
            QString r = query.value(0).toString(); // récupère id
            td.setId(r.toInt());

            r = query.value(1).toString(); // récupère Contenu
            td.setContenu(r.toStdString());

            r = query.value(2).toString(); // récupère Date
            Date d(r.toStdString());
            td.setDate(d);

            listTd.push_back(td);
        }
        emit envListTd(listTd);
    }
}

void QuerySQL::getAllAITS()
{
    cout << "SQL <-- Tentative de récupération des associations de la bdd..." << endl;
    QSqlQuery query;
    query.prepare("SELECT idAIT,todo, interaction, idContact FROM AssociationInteractionTodo");
    if (!query.exec())
    {
        qDebug() << "SQL --> Erreur pour récupérer les associations de la BDD";
            qDebug() << "SQL --> Erreur SQL : " << query.lastError().text();
    }
    else
    {
        qDebug() << "SQL --> Récupération réussie !";     
        list<list<int>> listAIT;

        while (query.next()) {
            list<int> ait;
            QString r = query.value(0).toString(); // récupère id
            ait.push_back(r.toInt());

            r = query.value(1).toString(); // récupère idTodo
            ait.push_back(r.toInt());

            r = query.value(2).toString(); // récupère idInteraction
            ait.push_back(r.toInt());

            r = query.value(3).toString(); // récupère idInteraction
            ait.push_back(r.toInt());

            listAIT.push_back(ait);
        }
        emit envListAIT(listAIT);
    }
}
