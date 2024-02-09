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

    std::vector<Task> getVector();

    void setTaskAsCompleted(int index);

    void sortByPriority();

    static bool comparePriority(Task a, Task b);

    void sortByDate();

    static bool compareDate(Task a, Task b);

    void sortByAlphabet();

    static bool compareAlphabet(Task a, Task b);
    std::vector<Task> getImportantTask();
    std::vector<Task> getExpiringTask();
    int completedTask();

private:
    std::vector<Task> tasks;
};


#endif //TODOLIST_TASKLIST_H
