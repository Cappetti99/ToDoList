//
// Created by cappe on 22/09/23.
//

#include "TaskListView.h"

TaskListView::TaskListView(const wxString &title, const wxPoint &pos, const wxSize &size) {

}

/*
void TaskListView::addTaskButton(wxCommandEvent &event) {

}

void TaskListView::removeTaskButton(wxCommandEvent &event) {

}

void TaskListView::searchTaskButton(wxCommandEvent &event) {

}

void TaskListView::moveTaskToAnotherList(wxCommandEvent &event) {

}

void TaskListView::sortButton(wxCommandEvent &event) {

}
*/

//fixme questo oppure questo dopo
/*
 TaskListView::TaskListView(const wxString& title, const TaskList& taskList)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)), taskList(taskList) {

    // Create UI elements
    taskListBox = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxLB_SINGLE);
    addButton = new wxButton(this, wxID_ANY, "Add Task");
    removeButton = new wxButton(this, wxID_ANY, "Remove Task");
    sortButton = new wxButton(this, wxID_ANY, "Sort Tasks");
    searchButton = new wxButton(this, wxID_ANY, "Search Tasks");

    // Set up event handlers for buttons
    // Connect addButton, removeButton, sortButton, and searchButton to respective event handlers.

    // Populate the taskListBox with tasks from the taskList
    for (const Task& task : taskList.getTasks()) {
        taskListBox->Append(task.getTitle());
    }
}
 */