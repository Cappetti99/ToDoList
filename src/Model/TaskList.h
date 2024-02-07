//
// Created by cappe on 13/12/23.
//

#ifndef TODOLIST_TASKLIST_H
#define TODOLIST_TASKLIST_H

#include <wx/wx.h>

#include "Task.h"
#include "Model.h"

//eredita model e subject

class TaskList : public Model {

public:
    TaskList();

    ~TaskList() override;

    //metodi di model
    void addTask(wxString name, wxDateTime date, Priority priority, bool completed) override;

    void removeTask(int index) override;

    //metodi di subject
    void notify() override;

    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void editTask(int index, wxString name, wxDateTime date, Priority priority) override;

    static bool compareTasks(Task a, Task b);

    std::vector<Task> getVector();

    void setTaskAsCompleted(int index);

private:
    std::vector<Task> tasks;
};


#endif //TODOLIST_TASKLIST_H
