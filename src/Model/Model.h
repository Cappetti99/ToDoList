//
// Created by cappe on 01/02/24.
//

#ifndef TODOLIST_MODEL_H
#define TODOLIST_MODEL_H

#include <wx/wx.h>
#include <list>

#include "../View/Priority.h"
#include "../Subject.h"


class Model : public Subject {

public:
    virtual ~Model();

    virtual void addTask(wxString title, wxDateTime date, Priority priority, bool completed) = 0;

    virtual void removeTask(int index) = 0;

    virtual void editTask(int index, wxString name, wxDateTime date, Priority priority) = 0;

protected:
    std::list<Observer *> observers;
};


#endif //TODOLIST_MODEL_H
