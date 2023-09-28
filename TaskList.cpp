//
// Created by cappe on 22/09/23.
//

#include <wx/datectrl.h>
#include <wx/wx.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <wx/textctrl.h>
#include <wx/font.h>
#include <wx/image.h>

#include "TaskList.h"

TaskList::TaskList() {

}

void TaskList::addTask() {
    wxString task = taskTextCtrl->GetValue();

    if (!task.IsEmpty()) {
        // Date Selection
        wxDialog dateDialog(reinterpret_cast<wxWindow *>(this), wxID_ANY, "Select expiration date:"); //todo va inserita la finestra
        wxDatePickerCtrl* datePicker = new wxDatePickerCtrl(&dateDialog, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT);
        wxBoxSizer* dateSizer = new wxBoxSizer(wxVERTICAL);
        dateSizer->Add(datePicker, 0, wxALL | wxEXPAND, 5);
        dateDialog.SetSizerAndFit(dateSizer);

        if (dateDialog.ShowModal() == wxID_OK) {
            wxDateTime expirationDate = datePicker->GetValue();
            wxString expirationDateStr = expirationDate.Format("%d %B, %Y");

            // Priority Selection
            wxArrayString priorityChoices;
            priorityChoices.Add("High");
            priorityChoices.Add("Medium");
            priorityChoices.Add("Low");

            int selectedPriorityIndex = wxGetSingleChoiceIndex("Select priority:", "Priority Selection", priorityChoices);

            if (selectedPriorityIndex != wxNOT_FOUND) {
                wxString selectedPriority = priorityChoices[selectedPriorityIndex];

                Task newTask;
                newTask.setTitle(task);
                newTask.setExpirationDate(expirationDate);
                newTask.setPriority(selectedPriority);
                newTask.setCompleted(false);
                tasks.push_back(newTask);

                // RefreshTaskList(); // Refresh the task list to include the new task
                taskTextCtrl->Clear();
            }
        }
    }
}

void TaskList::removeTask() {
    int selectedIndex = taskCheckBox->GetSelection();
    if (selectedIndex != wxNOT_FOUND) {
        wxMessageDialog confirmDialog(reinterpret_cast<wxWindow *>(this),
                                      "Are you sure you want to delete this task?", "Confirm Deletion",
                                      wxYES_NO | wxICON_QUESTION); //todo inserire window

        int response = confirmDialog.ShowModal();

        if (response == wxID_YES) {
            tasks.erase(tasks.begin() + selectedIndex);
            //RefreshTaskList();
            taskTextCtrl->Clear();
        }
    }

}

void TaskList::sortTask() {

}

std::vector<Task> TaskList::searchTask() {
    return std::vector<Task>();
}

void TaskList::swapTask() {

}

void TaskList::addList() {

}

void TaskList::removeList() {

}

void TaskList::searchList() {

}

void TaskList::renameList() {

}
