#include "gestioncontacts.h"


GestionContacts::GestionContacts()
{

}

GestionContacts::~GestionContacts()
{

}

void GestionContacts::setListContacts(list<Contact> liste)
{
    this->lContacts = liste;
}

list<Contact> GestionContacts::getListContacts() const
{
    return lContacts;
}

list<Contact>& GestionContacts::getListContacts()
{
    return lContacts;
}

Contact GestionContacts::getContactByName(const string& n)
{
    Contact c1;
    for(Contact c : lContacts)
        if(c.getNom() == n) c1 = c;
    return c1;
}

Contact GestionContacts::getContactByEntreprise(const string& e)
{
    Contact c1;
    for(Contact c : lContacts)
        if(c.getEntreprise() == e) c1 = c;
    return c1;
}
Contact GestionContacts::getContactByNameSurname(const string &n,const string &p)
{
    Contact c1;
    for(Contact c : lContacts)
        if(c.getNom() == n && c.getPrenom() == p) c1 = c;
    return c1;
}
Contact GestionContacts::getContactByDate( Date& d)
{
    Contact c1;
    for(Contact c : lContacts)
        if(c.getCreation().getJour() == d.getJour())
            if(c.getCreation().getMois() == d.getMois())
                if(c.getCreation().getAnnee() == d.getAnnee())
                    c1 = c;
    return c1;
}

GestionContacts GestionContacts::getContactsByIntervalle(Date& debut, Date& fin)
{
    GestionContacts contacts;
    for(Contact c : lContacts)
        if(c.getCreation().getJour() >= debut.getJour() && c.getCreation().getJour() <= fin.getJour())
            if(c.getCreation().getMois() >= debut.getMois() && c.getCreation().getMois() <= fin.getMois())
                if(c.getCreation().getAnnee() >= debut.getAnnee() && c.getCreation().getAnnee() <= fin.getAnnee())
                    contacts.ajoutContact(c);
    return contacts;
}

Contact* GestionContacts::getContactById(const int &id)
{
    Contact* find;
    for(Contact &c : lContacts)
    {
        if(c.getId() == id)
        {
            find = &c;
            return find;
        }
    }
}

int GestionContacts::getNbrContacts()
{
    return lContacts.size();
}
void GestionContacts::trier_date_creation(list<Contact> &liste)
{
    liste.sort([liste](const Contact &c1, const Contact &c2) {
        return c1.getCreation() < c2.getCreation();
    });
}
GestionContacts GestionContacts::operator+(const Contact &c) {
    Contact nv = c;
    if(lContacts.size() < 1)
        nv.setId(1);
    else
        nv.setId(lContacts.back().getId()+1);
    lContacts.push_back(nv);
    return *this;
}

void GestionContacts::operator=(const GestionContacts &gc) {
    lContacts.clear();
    lContacts = gc.lContacts;
}


GestionContacts GestionContacts::operator-(const Contact &c)
{
    auto it = lContacts.begin();
    bool found = false;
    while ((it != lContacts.end()) && !found) {
        if (*it == c)
        {
            found = true;
            it = lContacts.erase(it);
        } else
            ++it;
    }
    return *this;
}
//


void GestionContacts::ajoutContact(Contact &c)
{
    Contact nv = c;
    if(lContacts.size() < 1)
        nv.setId(1);
    else
        nv.setId(lContacts.back().getId()+1);
    lContacts.push_back(nv);
}

void GestionContacts::suppContact(Contact &c)
{
    lContacts.remove(c);
}


ostream &operator<<( ostream& os, const GestionContacts& gc )
{
    for(Contact c : gc.lContacts)
    {
        os << '-' << c.getId() << " : "<< c << endl;
    }
    return os;
}
