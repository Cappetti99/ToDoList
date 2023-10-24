//
// Created by cappe on 22/09/23.
//

#include "TaskListListView.h"
#include "Task.h"

/*
wxBEGIN_EVENT_TABLE(TaskListListView, wxFrame)
        EVT_BUTTON(ID_AddList ,TaskListListController::OnAddListButtonClick);
        EVT_BUTTON(ID_RenameList ,TaskListListController::OnEditListButtonClick);
        EVT_BUTTON(ID_RemoveList,TaskListListController::OnRemoveListButtonClick);
        EVT_BUTTON(ID_SearchList, TaskListListController::OnSearchListButtonClick);
wxEND_EVENT_TABLE()
*/
    TaskListListView::TaskListListView(wxWindow* parent, const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(parent, wxID_ANY, title, wxDefaultPosition, wxDefaultSize){

    auto mainSizer = new wxBoxSizer(wxVERTICAL);

    auto taskTextCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize,
                                       wxTE_PROCESS_ENTER);
    //mainSizer->Add(taskTextCtrl, 0, wxEXPAND | wxALL, 5);

    wxButton* addListButton = new wxButton(this, ID_AddList, "Add List");
    auto removeListButton = new wxButton(this, ID_RemoveList, "Remove List");
    auto searchListButton = new wxButton(this, ID_SearchList, "Search List");
    auto renameListButton = new wxButton(this, ID_RenameList, "Rename List");

    //addListButton->Bind(wxEVT_BUTTON, &TaskListListView::OnAddListButtonClick, this, ID_AddList);

    auto buttonsSizer = new wxBoxSizer(wxHORIZONTAL);

    buttonsSizer->Add(addListButton, 5, wxALL, 10);
    buttonsSizer->Add(removeListButton, 5, wxALL, 10);
    buttonsSizer->Add(searchListButton, 5, wxALL, 10);
    buttonsSizer->Add(renameListButton, 5, wxALL, 10);

    mainSizer->Add(buttonsSizer, 0, wxALIGN_LEFT);
    mainSizer->Add(taskTextCtrl, 0, wxALL | wxEXPAND, 5);


    auto listBoxSizer = new wxBoxSizer(wxVERTICAL);

    taskListList = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxLB_SINGLE);
    listBoxSizer->Add(taskListList, 1, wxEXPAND | wxALL, 10);

    mainSizer->Add(listBoxSizer, 1, wxEXPAND | wxALL, 5);

    this->SetSizer(mainSizer);

}

wxTextCtrl *TaskListListView::getTaskTextCtrl() const {
    return taskTextCtrl;
}

void TaskListListView::setTaskTextCtrl(wxTextCtrl *taskTextCtrl) {
    TaskListListView::taskTextCtrl = taskTextCtrl;
}




void TaskListListView::OnAddListButtonClick() {
        /* QUESTA ROBA VA SU TASKLISTVIEW

    Task* task = new Task;
    wxString title = wxGetTextFromUser("Enter title:");
    DateSelectionDialog dateDialog(nullptr, "Select expiration date:");

    if (dateDialog.ShowModal() == wxID_OK) {
        wxDatePickerCtrl *datePicker = dateDialog.getDatePicker();
        wxDateTime expirationDate = datePicker->GetValue();
        wxString expirationDateStr = expirationDate.Format("%d %B, %Y");

        PrioritySelectionDialog priorityDialog(nullptr, "Select priority:");

        if (priorityDialog.ShowModal() == wxID_OK) {
            Priority selectedPriority = priorityDialog.getSelectedPriority();


            return std::make_tuple(expirationDate, title, selectedPriority);
        }


    }
         */
}


wxButton *TaskListListView::getAddListButton() const {
    return addListButton;
}





