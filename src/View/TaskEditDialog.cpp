//
// Created by cappe on 05/02/24.
//

#include "TaskEditDialog.h"

wxBEGIN_EVENT_TABLE(TaskEditDialog, wxDialog)
                EVT_BUTTON(wxID_OK, TaskEditDialog::OnOK)
                EVT_BUTTON(wxID_CANCEL, TaskEditDialog::OnCancel)
wxEND_EVENT_TABLE()

TaskEditDialog::TaskEditDialog(wxWindow *parent, const wxString &title, const wxString &taskTitle,
                               const wxDateTime &expirationDate, Priority priority)
                               : wxDialog(parent, wxID_ANY,title, wxDefaultPosition, wxDefaultSize){

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    taskTextCtrl = new wxTextCtrl(this, wxID_ANY, taskTitle);
    mainSizer->Add(taskTextCtrl, 0, wxEXPAND | wxALL, 5);

    expirationDatePicker = new wxDatePickerCtrl(this, wxID_ANY, expirationDate, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT | wxDP_SHOWCENTURY);
    mainSizer->Add(expirationDatePicker, 0, wxEXPAND | wxALL, 5);



    wxString priorityChoices[] = {"Low", "Medium", "High" };
    priorityChoice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 3, priorityChoices);
    mainSizer->Add(priorityChoice, 0, wxEXPAND | wxALL, 5);

    okButton = new wxButton(this, wxID_OK, "OK");
    cancelButton = new wxButton(this, wxID_CANCEL, "Cancel");
    //intercambiando questi due bottoni si cambia anche la posizione di ok e cancel

    wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
    buttonSizer->Add(okButton, 0, wxALL, 5);
    buttonSizer->Add(cancelButton, 0, wxALL, 5);

    mainSizer->Add(buttonSizer, 0, wxALIGN_RIGHT);

    SetSizerAndFit(mainSizer);

    taskTextCtrl->SetValue(taskTitle);
    expirationDatePicker->SetValue(expirationDate);
    priorityChoice->SetSelection((int) priority);


}

void TaskEditDialog::OnOK(wxCommandEvent &event) {
    editedTaskTitle = taskTextCtrl->GetValue();
    editedExpirationDate = expirationDatePicker->GetValue();
    editedPriority = (Priority) priorityChoice->GetSelection();
    EndModal(wxID_OK);
}

void TaskEditDialog::OnCancel(wxCommandEvent &event) {
    EndModal(wxID_CANCEL);
}

wxString TaskEditDialog::getTaskTitle() {
    return editedTaskTitle;
}

wxDateTime TaskEditDialog::getExpirationDate() {
    return editedExpirationDate;
}

Priority TaskEditDialog::getPriority() {
    return editedPriority;
}