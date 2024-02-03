//
// Created by cappe on 13/12/23.
//

#ifndef TODOLIST_TODOITEM_H
#define TODOLIST_TODOITEM_H

#include <wx/wx.h>

#include "Task.h"
#include "Model.h"

//eredita model e subject

class ToDoItem : public Model{

public:
    ToDoItem();

    ~ToDoItem() override;

    //metodi di model
    void addTask(wxString name, wxDateTime date, Priority priority) override;

    void removeTask(int index) override;

    //metodi di subject
    void notify() override;

    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    std::vector<Task> getVector();  //todo togliere getVector

    wxString getName(int index);

    wxDateTime getDate(int index);

    Priority getPriority(int index);

    void setTaskAsCompleted(int index);

    bool isCompleted(int index);

private:

    std::vector<Task> tasks;
};


#endif //TODOLIST_TODOITEM_H
