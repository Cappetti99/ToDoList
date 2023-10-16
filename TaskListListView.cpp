//
// Created by cappe on 22/09/23.
//

#include "TaskListListView.h"

TaskListListView::TaskListListView(wxWindow *parent, const wxString &title, const wxPoint &pos, const wxSize &size)
        : wxFrame(parent, wxID_ANY, title, wxDefaultPosition, wxDefaultSize) {

    auto mainSizer = new wxBoxSizer(wxVERTICAL);

    auto taskTextCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize,
                                       wxTE_PROCESS_ENTER);
    //mainSizer->Add(taskTextCtrl, 0, wxEXPAND | wxALL, 5);

    auto addListButton = new wxButton(this, wxID_ANY, "Add List");
    auto removeListButton = new wxButton(this, wxID_ANY, "Remove List");
    auto searchListButton = new wxButton(this, wxID_ANY, "Search List");
    auto renameListButton = new wxButton(this, wxID_ANY, "Rename List");

    addListButton->Bind(wxEVT_BUTTON, &TaskListListView::OnAddListButtonClick, this, wxID_ANY);

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


void TaskListListView::OnAddListButtonClick(wxCommandEvent &event) {


    Task* task = new Task;
    task->addTask();


    //Task* task = new Task(getTaskTextCtrl()->GetValue());
    //task.addTask();
    //&Task::addTask;
    printf("gay");


}





