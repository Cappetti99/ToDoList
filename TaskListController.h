//
// Created by cappe on 22/09/23.
//

#ifndef TODOLIST_TASKLISTCONTROLLER_H
#define TODOLIST_TASKLISTCONTROLLER_H

#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/listctrl.h>
#include <vector>
#include <wx/richtext/richtextctrl.h>
#include <wx/colour.h>
#include <wx/textctrl.h>

#include "TaskListView.h"

class TaskListController {

public:
    TaskListController(TaskList& model);

    void addTaskButton(wxCommandEvent& event);
    void removeTaskButton(size_t index);
    void sortTaskButton();
    void searchTaskButton(const wxString& searchTerm);
    //void renameListButton(const wxString& newName);

private:
    //funzioni
/*    void addTask();
    void removeTask();
    std::vector<Task> searchTask();
    void sortTask();
    void swapList();
    void addList();
    void removeList();
    void searchList();
    void renameList();
    */

    //variabili
    TaskList& model;  //non ricordo a che serve
    //TaskListView& view;  //non ricordo a che serve

};


#endif //TODOLIST_TASKLISTCONTROLLER_H
