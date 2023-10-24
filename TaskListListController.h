//
// Created by cappe on 22/09/23.
//

#ifndef TODOLIST_TASKLISTLISTCONTROLLER_H
#define TODOLIST_TASKLISTLISTCONTROLLER_H


#include <wx/wx.h>

#include "TaskListListView.h"
#include "TaskList.h"


//QUESTA CONTROLLA LA CLASSE PIU' ESTERNA
//non so se ok dichiararlo come object
class TaskListListController : public wxObject {

public:
    TaskListListController(TaskList *model, TaskListListView *view);




private:
    TaskList *model;
    TaskListListView * view;

    void AddListButton(wxCommandEvent &event);
    void RemoveListButton(wxCommandEvent &event);
    void SearchListButton(wxCommandEvent &event);
    void RenameListButton(wxCommandEvent &event);


    wxFrame* frame;

    //wxDECLARE_EVENT_TABLE();
};

//todo c'è da implementare il costruttore?


#endif //TODOLIST_TASKLISTLISTCONTROLLER_H
