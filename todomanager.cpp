#include "todomanager.h"


TodoManager::TodoManager()
{
}

TodoManager::~TodoManager()
{
}

void TodoManager::ajouterTodo(const Todo &td) {
    Todo nvTd = td;
    nvTd.setId(todos.size()+1);
    todos.push_back(nvTd);
}

void TodoManager::suppTodo(const Todo &todo)
{
    auto it = todos.begin();
    bool found = false;
    while ((it != todos.end()) && !found) {
        if (it->getId() == todo.getId())
        {
            found = true;
            it = todos.erase(it);
        } else
            ++it;
    }
}

void TodoManager::associerTodoAInteraction(Todo &nvTodo, Interaction &interactionALier) {
    ajouterTodo(nvTodo);

    associerPointeurTodoInteraction(&todos.back(),&interactionALier);
}

void TodoManager::associerPointeurTodoInteraction(Todo* todo, Interaction *interaction) {
    AssociationInteractionTodo nvAssociation(interaction, todo);

    if(associations.size() < 1)
        nvAssociation.setId(1);
    else
        nvAssociation.setId(associations.size()+1);
    associations.push_back(nvAssociation);

}

void TodoManager::dissocierTodoAInteraction(Todo & todo) {
    auto it = associations.begin();
    bool found = false;
    while ((it != associations.end()) && !found) {
        if (it->getTodo().getId() == todo.getId())
        {
            found = true;
            it = associations.erase(it); // suppression de l'association
        } else
            ++it;
    }
}

TodoManager TodoManager::todoManagerByIdContact(int id){
    TodoManager res;
    list<Todo> listTodo;
    list<AssociationInteractionTodo> listAIT;
    cout << "Todomanager By Id Contact..." << endl;
    for(AssociationInteractionTodo &ait : getAssociations()) // Parcours table d'association
    {
        if (ait.getInteraction().getIdContact() == id) // Si une interaction d'un contact est en association avec un todo
        {
            cout << "Contact trouvé !" << endl;
            listAIT.push_back(ait);
            listTodo.push_back(ait.getTodo());
        }
    }
    res.setListAssociation(listAIT);
    res.setListTodo(listTodo);
    return res;
}

list<Todo> TodoManager::getTodos() const {
    return todos;
}
Todo* TodoManager::getTodo(int id)
{
    Todo* find;
    for(Todo &td : todos)
    {
        if(td.getId() == id)
        {
            find = &td;
            return find;
        }
    }
}

void TodoManager::setListTodo(list<Todo> listeTodo)
{
    this->todos = listeTodo;
}

list<AssociationInteractionTodo> TodoManager::getAssociations() const
{
    return associations;
}

void TodoManager::setListAssociation(list<AssociationInteractionTodo> listAssociation)
{
    this->associations = listAssociation;
}
