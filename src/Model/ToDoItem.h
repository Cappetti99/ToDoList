//
// Created by cappe on 13/12/23.
//

#ifndef LOLLO_TODOITEM_H
#define LOLLO_TODOITEM_H

#include <wx/wx.h>
#include <memory>

#include "Task.h"


class ToDoItem {

private:


public:
    ToDoItem();

    void addTask(wxString name, wxDateTime date, Priority priority);

    void removeTask(int index);

    std::vector<Task> getVector();

    wxString getName(int index);

    wxDateTime getDate(int index);

    Priority getPriority(int index);

    std::vector<Task> tasks;


};


#endif //LOLLO_TODOITEM_H
