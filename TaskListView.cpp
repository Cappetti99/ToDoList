//
// Created by cappe on 22/09/23.
//

#include "TaskListView.h"

/*
TaskListView::TaskListView(const wxString &title, const wxPoint &pos, const wxSize &size) {

}


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

 TaskListView::TaskListView(const wxString& title, const wxPoint& pos, const wxSize& size)
: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)), taskList(taskList) {

    // Create UI elements
    taskListBox = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxLB_SINGLE);
    addButton = new wxButton(this, wxID_ANY, "Add Task");
    removeButton = new wxButton(this, wxID_ANY, "Remove Task");
    sortButton = new wxButton(this, wxID_ANY, "Sort Tasks");
    searchButton = new wxButton(this, wxID_ANY, "Search Tasks");

    auto* buttonsSizer = new wxBoxSizer(wxHORIZONTAL);
    buttonsSizer->Add(addButton, 0, wxALL, 10);
    buttonsSizer->Add(removeButton, 0, wxALL, 10);
    buttonsSizer->Add(sortButton, 0, wxALL, 10);
    buttonsSizer->Add(searchButton, 0, wxALL, 10);
    


    // Populate the taskListBox with tasks from the taskList
    /*for (const Task& task : taskList.getTasks()) {
        taskListBox->Append(task.getTitle());
    }*/
}

/*QUESTO VA QUI
std::tuple<wxDateTime,wxString,Priority> TaskListListView::OnAddTaskButtonClick() {

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