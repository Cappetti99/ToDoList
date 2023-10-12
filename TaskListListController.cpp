//
// Created by cappe on 22/09/23.
//

#include "TaskListListController.h"


TaskListListController::TaskListListController(TaskList * model, TaskListListView * view) : model(model), view(view) {
       view->Bind(wxEVT_BUTTON, &TaskListListController::OnAddListButtonClick,this,wxID_ANY);
       view->Bind(wxEVT_BUTTON, &TaskListListController::OnEditListButtonClick,this,wxID_ANY);
       view->Bind(wxEVT_BUTTON, &TaskListListController::OnRemoveListButtonClick,this,wxID_ANY);
       view->Bind(wxEVT_BUTTON, &TaskListListController::OnSearchListButtonClick,this,wxID_ANY);
   }


   void TaskListListController::Run() {
       TaskListListView* toDoFrame  = new TaskListListView(frame, "My Todo list by Cappetti e Collini", wxPoint(50, 50), wxSize(400, 300));
       toDoFrame->SetClientSize(800,600);
       toDoFrame->Center();
       toDoFrame->Show(true);
   }

   void TaskListListController::OnAddListButtonClick(wxCommandEvent &event) {
//       wxString taskName = (view->getTaskTextCtrl())->GetValue();
//       model->addList(taskName);
//non va bene perchè stiamo passando un nome al posto di una task

   }

   void TaskListListController::OnSearchListButtonClick(wxCommandEvent &event) {

   }

   void TaskListListController::OnRemoveListButtonClick(wxCommandEvent &event) {

   }

   void TaskListListController::OnEditListButtonClick(wxCommandEvent &event) {

}