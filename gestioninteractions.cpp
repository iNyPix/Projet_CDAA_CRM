#include "gestioninteractions.h"


GestionInteractions::GestionInteractions()
{

}

GestionInteractions::~GestionInteractions(){}

list<Interaction> GestionInteractions::getList()
{
    return linteractions;
}

int GestionInteractions::getSize()
{
    return linteractions.size();
}

Interaction GestionInteractions::rechInteraction(Interaction &rech)
{
    Interaction res;
    for(Interaction &i : linteractions)
    {
        if(i.getId() == rech.getId())
            return i;
    }
    return res;
}

Interaction* GestionInteractions::rechInteraction(int id)
{
    Interaction *res;

    for(auto i = linteractions.begin(); i != linteractions.end() ; ++i)
    {
        if(i->getId() == id)
        {
            res = &*i;
        }

    }
    return res;
}

void GestionInteractions::addInteraction(Interaction &i) {
    if(linteractions.size() < 1)
        i.setId(1);
    else
        i.setId(linteractions.back().getId()+1);
    linteractions.push_back(i);
}

void GestionInteractions::suppInteraction(int id)
{
    for(auto i = linteractions.begin(); i != linteractions.end() ; ++i)
    {
        if(i->getId() == id)
        {

            linteractions.erase(i);
            break;
        }
    }
}

void GestionInteractions::trier_date_modification(list<Interaction> &liste)
{
    liste.sort([liste](const Interaction &i1, const Interaction &i2) {
        return i1.getDateModif() < i2.getDateModif();
    });
}
