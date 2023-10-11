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

#include "TaskList.h"
#include "TaskListListView.h"

#include "Task.h"
#include "TaskListListView.h"

//QUESTA CONTROLLA LA CLASSE PIU' ESTERNA

class TaskListListController {

public:
    TaskListListController(TaskList * model, TaskListListView * view);
    void Run();
    //c'era anche TaskListListView& view; nel costruttore ma dava problemi dicendo che non era dichiarato
   /* void addList(const TaskList& taskList);
    void removeList(size_t index);
    void searchList(const wxString& searchTerm);
    void renameList(const wxString& newName);*/

private:
    TaskList* model;
    TaskListListView* view;

    void OnAddListButtonClick(wxCommandEvent& event);
    void OnRemoveListButtonClick(wxCommandEvent& event);
    void OnSearchListButtonClick(wxCommandEvent& event);
    void OnEditListButtonClick(wxCommandEvent& event);
    wxFrame* frame;
};

//todo c'è da implementare il costruttore?


#endif //TODOLIST_TASKLISTLISTCONTROLLER_H
