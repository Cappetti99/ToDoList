//
// Created by cappe on 13/12/23.
//

#ifndef LOLLO_TODOITEM_H
#define LOLLO_TODOITEM_H

#include <wx/wx.h>
#include <memory>

#include "Task.h"


class ToDoItem {


public:
    ToDoItem();

    void addTask(wxString name, wxDateTime date, Priority priority);

    void removeTask(int index);

    std::vector<Task> getVector();  //todo togliere getVector

    wxString getName(int index);

    wxDateTime getDate(int index);

    Priority getPriority(int index);

    void setTaskAsCompleted(int index);

    bool getCompleted(int index);

private:

    std::vector<Task> tasks;
};


#endif //LOLLO_TODOITEM_H
