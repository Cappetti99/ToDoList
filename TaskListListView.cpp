//
// Created by cappe on 22/09/23.
//

#include "TaskListListView.h"

TaskListListView::TaskListListView(const wxString& title, const std::vector<TaskList>& taskLists)
        : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)), taskLists(taskLists) {

    // Create UI elements
    taskListListBox = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxLB_SINGLE);
    addListButton = new wxButton(this, wxID_ANY, "Add List");
    removeListButton = new wxButton(this, wxID_ANY, "Remove List");
    searchListButton = new wxButton(this, wxID_ANY, "Search List");
    renameListButton = new wxButton(this, wxID_ANY, "Rename List");

    auto* buttonsSizer = new wxBoxSizer(wxHORIZONTAL);
    buttonsSizer->Add(addListButton, 0, wxALL, 10);
    buttonsSizer->Add(removeListButton, 0, wxALL, 10);
    buttonsSizer->Add(searchListButton, 0, wxALL, 10);
    buttonsSizer->Add(renameListButton, 0, wxALL, 10);

    // Set up event handlers for buttons
    // Connect addListButton, removeListButton, searchListButton, and renameListButton to respective event handlers.

    // Populate the taskListListBox with list names from the taskLists
    for (const TaskList& taskList : taskLists) {
        taskListListBox->Append(taskList.getName());
    }
}

