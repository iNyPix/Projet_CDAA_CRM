#include "todo.h"

Todo::Todo()
{
}
Todo::Todo(string s, Date d)
{
    this->contenu = s;
    this->date = d;
}
Todo::Todo(string s)
{
    this->contenu = s;
    this->date = Date::getDateActuelle();
}
Todo::~Todo() {}

// Getters
string Todo::getContenu()
{
    return this->contenu;
}

Date Todo::getDate()
{
    return this->date;
}
int Todo::getId() const
{
    return this->idTodo;
}

// Setters
void Todo::setContenu(string contenu)
{
    this->contenu = contenu;
}

void Todo::setDate(Date date)
{
    this->date = date;
}
void Todo::setId(int id)
{
    this->idTodo = id;
}
string Todo::affiche()
{
    string res;
    if (!(date == Date::getDateActuelle()))
        res = "@todo " + contenu + " @date " + date.affiche(); // Si date différente de date courante on affiche la date
    else
        res = "@todo " + contenu; // Si date est la date courante on n'affiche pas la date
    return res;
}

std::ostream& operator<<(std::ostream& os, const Todo& t) {
    Date d = t.date;
    if (!(d == Date::getDateActuelle()))
        os << "@todo " << t.contenu << " @date " << t.date; // Si date différente de date courante on affiche la date
    else
        os << "@todo " << t.contenu; // Si date est la date courante on n'affiche pas la date
    return os;
}
