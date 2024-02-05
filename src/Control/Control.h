//
// Created by cappe on 13/12/23.
//

#ifndef TODOLIST_CONTROLL_H
#define TODOLIST_CONTROLL_H

#include <wx/wx.h>

#include "../Model/Model.h"


class Control {

public:

    virtual ~Control();

    virtual void addTask(wxString name, wxDateTime date, Priority priority) = 0;

    virtual void removeTask(int index) = 0;

    virtual void searchTask() = 0;

    virtual void markAsCompleted(int index) = 0;

    virtual void editTask(int index, wxString name, wxDateTime date, Priority priority) = 0;

protected:
    Model *model;
};


#endif //TODOLIST_CONTROLL_H
