//
// Created by cappe on 22/09/23.
//

#include "TaskListListView.h"
//    void OnOpenButtonClick(wxCommandEvent& event);

    TaskListListView::TaskListListView(wxWindow* parent, const wxString& title, const std::vector<TaskList>& taskLists)
        : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize), taskLists(taskLists) {

    auto* addListButton = new wxButton(this, wxID_ANY, "Add List");
    auto* removeListButton = new wxButton(this, wxID_ANY, "Remove List");
    auto* searchListButton = new wxButton(this, wxID_ANY, "Search List");
    auto* renameListButton = new wxButton(this, wxID_ANY, "Rename List");

    auto* buttonsSizer = new wxBoxSizer(wxHORIZONTAL);

    buttonsSizer->Add(addListButton, 2, wxALL, 10);
    buttonsSizer->Add(removeListButton, 2, wxALL, 10);
    buttonsSizer->Add(searchListButton, 2, wxALL, 10);
    buttonsSizer->Add(renameListButton, 2, wxALL, 10);

    this->SetSizer(buttonsSizer);

}

