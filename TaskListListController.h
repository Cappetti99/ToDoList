//
// Created by cappe on 22/09/23.
//

#ifndef TODOLIST_TASKLISTLISTCONTROLLER_H
#define TODOLIST_TASKLISTLISTCONTROLLER_H


#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/listctrl.h>
#include <vector>
#include <wx/richtext/richtextctrl.h>
#include <wx/colour.h>
#include <wx/textctrl.h>

#include "Task.h"
#include "TaskListListView.h"

class TaskListListController {

public:
    TaskListListController(std::vector<TaskList>& models, TaskListListView& view);

    void addList(const TaskList& taskList);
    void removeList(size_t index);
    void searchList(const wxString& searchTerm);
    void renameList(const wxString& newName);

private:
    std::vector<Task> tasks;
    std::vector<TaskList>& models;
    TaskListListView& view;

};

//todo c'è da implementare il costruttore?


#endif //TODOLIST_TASKLISTLISTCONTROLLER_H
