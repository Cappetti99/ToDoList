//
// Created by cappe on 22/09/23.
//

#include "TaskListListController.h"
/*
wxBEGIN_EVENT_TABLE(TaskListListView, wxFrame)
        EVT_BUTTON(ID_AddList ,TaskListListController::AddListButton);
        EVT_BUTTON(ID_RemoveList,TaskListListController::OnRemoveListButtonClick);
        EVT_BUTTON(ID_SearchList, TaskListListController::OnSearchListButtonClick);
wxEND_EVENT_TABLE()
 ;*/

TaskListListController::TaskListListController(TaskList * model, TaskListListView * view){

    view->Bind(wxEVT_BUTTON, &TaskListListController::AddListButton, this, TaskListListView::ID_AddList);
    view->Bind(wxEVT_BUTTON, &TaskListListController::SearchListButton, this, TaskListListView::ID_SearchList);
    view->Bind(wxEVT_BUTTON, &TaskListListController::RemoveListButton, this, TaskListListView::ID_RemoveList);
    view->Bind(wxEVT_BUTTON, &TaskListListController::RenameListButton, this, TaskListListView::ID_RenameList);
}




   void TaskListListController::AddListButton(wxCommandEvent& event) {
       wxString taskName = (view->getTaskTextCtrl())->GetValue();
        view->OnAddListButtonClick();
       model->addList(taskName);
   }

   void TaskListListController::SearchListButton(wxCommandEvent &event) {

   }

   void TaskListListController::RemoveListButton(wxCommandEvent &event) {

   }

   void TaskListListController::RenameListButton(wxCommandEvent &event) {

}

