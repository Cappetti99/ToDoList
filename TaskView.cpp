//
// Created by cappe on 22/09/23.
//

#include "TaskView.h"

TaskView::TaskView(const wxString& title, const Task& task)
        : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 300)), task(task) {

    // Create UI elements
    taskListBox = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxLB_SINGLE);
    editButton = new wxButton(this, wxID_ANY, "Edit Task");

    // Set up event handlers for buttons
    // Connect editButton to an event handler for editing the task.

    // Display task details in the taskListBox
    // You can format and display task attributes as needed.
    taskListBox->Append("Title: " + task.getTitle());

    taskListBox->Append("Priority: " + wxString::FromUTF8(Task::PriorityToString(task.getPriority())));
    wxString StrCompleated = task.isCompleted() ? "Yes" : "No";
    taskListBox->Append("Completed: " + StrCompleated);
    taskListBox->Append("Expiration Date: " + task.getExpirationDate().Format());
}