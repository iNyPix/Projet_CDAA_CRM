//
// Created by thomas on 25/10/23.
//
#include "associationinteractiontodo.h"

AssociationInteractionTodo::AssociationInteractionTodo()
{
   // interaction = NULL;
   // todo = NULL;
}
AssociationInteractionTodo::AssociationInteractionTodo(Interaction * i, Todo * td)
{
    interaction = i;
    todo = td;
}
AssociationInteractionTodo::~AssociationInteractionTodo()
{}
void AssociationInteractionTodo::setId(int i)
{
    idAIT = i;
}
void AssociationInteractionTodo::setTodo(Todo *todo)
{
    this->todo = todo;
}
void AssociationInteractionTodo::setInteraction(Interaction *interaction)
{
    this->interaction = interaction;
}
int AssociationInteractionTodo::getId()
{
    return idAIT;
}
Todo AssociationInteractionTodo::getTodo()
{
    return *todo;
}
Interaction AssociationInteractionTodo::getInteraction()
{
    return *interaction;
}
ostream& operator<<(ostream &os, const AssociationInteractionTodo & ait)
{
    os << *ait.interaction << " " << *ait.todo;
    return os;
}
