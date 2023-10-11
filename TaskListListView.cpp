//
// Created by cappe on 22/09/23.
//

#include "TaskListListView.h"

    TaskListListView::TaskListListView(wxWindow* parent, const wxString& title, const std::vector<TaskList>& taskLists)
        : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize), taskLists(taskLists) {

    auto mainSizer = new wxBoxSizer(wxVERTICAL);

    auto taskTextCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
    //mainSizer->Add(taskTextCtrl, 0, wxEXPAND | wxALL, 5);

    auto addListButton = new wxButton(this, wxID_ANY, "Add List");
    auto removeListButton = new wxButton(this, wxID_ANY, "Remove List");
    auto searchListButton = new wxButton(this, wxID_ANY, "Search List");
    auto renameListButton = new wxButton(this, wxID_ANY, "Rename List");

    auto buttonsSizer = new wxBoxSizer(wxHORIZONTAL);

    buttonsSizer->Add(addListButton, 5, wxALL, 10);
    buttonsSizer->Add(removeListButton, 5, wxALL, 10);
    buttonsSizer->Add(searchListButton, 5, wxALL, 10);
    buttonsSizer->Add(renameListButton, 5, wxALL, 10);

    mainSizer->Add(buttonsSizer, 0, wxALIGN_LEFT);
    mainSizer->Add(taskTextCtrl, 0, wxALL | wxEXPAND, 5);


    wxBoxSizer* listBoxSizer = new wxBoxSizer(wxVERTICAL);

    taskListList = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxLB_SINGLE);
    listBoxSizer->Add(taskListList, 1, wxEXPAND | wxALL, 10);

    mainSizer->Add(listBoxSizer, 1, wxEXPAND | wxALL, 5);

    this->SetSizer(mainSizer);

}

