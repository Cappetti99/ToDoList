//
// Created by cappe on 22/09/23.
//

#ifndef TODOLIST_TASKLISTLISTCONTROLLER_H
#define TODOLIST_TASKLISTLISTCONTROLLER_H


#include <wx/wx.h>

#include "TaskListListView.h"


//QUESTA CONTROLLA LA CLASSE PIU' ESTERNA

class TaskListListController {

public:
    TaskListListController(TaskList *model, TaskListListView *view);

    void Run();


private:
    TaskList *model;
    TaskListListView * view;

    void OnAddListButtonClick(wxCommandEvent& event);
    void OnRemoveListButtonClick(wxCommandEvent& event);
    void OnSearchListButtonClick(wxCommandEvent& event);
    void OnEditListButtonClick(wxCommandEvent& event);
    wxFrame* frame;
};

//todo c'è da implementare il costruttore?


#endif //TODOLIST_TASKLISTLISTCONTROLLER_H
