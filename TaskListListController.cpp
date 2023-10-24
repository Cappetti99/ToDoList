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
}



   void TaskListListController::AddListButton(wxCommandEvent& event) {
       //wxString taskName = (view->getTaskTextCtrl())->GetValue();
        auto values =view->OnAddListButtonClick();
       wxDateTime a = std::get<0>(values);
       wxString b =std::get<1>(values);
       Priority c =std::get<2>(values);

       //model->addList();
       model->addTask1(a,b,c);
   }

   void TaskListListController::OnSearchListButtonClick(wxCommandEvent &event) {

   }

   void TaskListListController::OnRemoveListButtonClick(wxCommandEvent &event) {

   }

   void TaskListListController::OnEditListButtonClick(wxCommandEvent &event) {

}

