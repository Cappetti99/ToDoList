//
// Created by cappe on 22/12/23.
//

#include "PrioritySelectionDialog.h"

wxBEGIN_EVENT_TABLE(PrioritySelectionDialog, wxDialog)
                EVT_BUTTON(wxID_OK, PrioritySelectionDialog::OnOK)
                EVT_BUTTON(wxID_CANCEL, PrioritySelectionDialog::OnCancel)
wxEND_EVENT_TABLE()

PrioritySelectionDialog::PrioritySelectionDialog(wxWindow* parent, const wxString& title)
        : wxDialog(parent, wxID_ANY, title, wxDefaultPosition, wxDefaultSize) {

    selectedPriority = Priority::None;

    auto mainSizer = new wxBoxSizer(wxVERTICAL);

    lowButton = new wxRadioButton(this, wxID_ANY, "Low");
    mediumButton = new wxRadioButton(this, wxID_ANY, "Medium");
    highButton = new wxRadioButton(this, wxID_ANY, "High");

    okButton = new wxButton(this, wxID_OK, "OK");
    cancelButton = new wxButton(this, wxID_CANCEL, "Cancel");

    auto buttonSizer = new wxBoxSizer(wxHORIZONTAL);
    buttonSizer->Add(cancelButton, 0, wxALL, 5);
    buttonSizer->Add(okButton, 0, wxALL, 5);

    mainSizer->Add(lowButton, 0, wxALL, 5);
    mainSizer->Add(mediumButton, 0, wxALL, 5);
    mainSizer->Add(highButton, 0, wxALL, 5);
    mainSizer->Add(buttonSizer, 0, wxALIGN_RIGHT);

    SetSizerAndFit(mainSizer);
}

void PrioritySelectionDialog::OnOK(wxCommandEvent& event) {
    if (lowButton->GetValue()) {
        selectedPriority = Priority::Low;
    } else if (mediumButton->GetValue()) {
        selectedPriority = Priority::Medium;
    } else if (highButton->GetValue()) {
        selectedPriority = Priority::High;
    }

    EndModal(wxID_OK);
}

void PrioritySelectionDialog::OnCancel(wxCommandEvent& event) {
    EndModal(wxID_CANCEL);
    selectedPriority = Priority::None;
}

Priority PrioritySelectionDialog::getSelectedPriority() const {
    return selectedPriority;
}