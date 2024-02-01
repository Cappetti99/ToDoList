//
// Created by cappe on 01/02/24.
//

#ifndef TODOLIST_MODEL_H
#define TODOLIST_MODEL_H

#include <list>

#include "../Subject.h"
#include "ToDoItem.h"

class Model : public Subject {

public:
    virtual void addObserver(Observer *o);

    virtual void removeObserver(Observer *o);

    virtual void notify();

    void addTask(wxString title, wxDateTime date, Priority priority);

private:
    std::list<Observer *> observers;



};


#endif //TODOLIST_MODEL_H
