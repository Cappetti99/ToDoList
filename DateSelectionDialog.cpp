//
// Created by cappe on 11/10/23.
//

#include "DateSelectionDialog.h"


DateSelectionDialog::DateSelectionDialog(wxWindow* parent, const wxString& title)
        : wxDialog(parent, wxID_ANY, title, wxDefaultPosition, wxDefaultSize) {
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    SetSizer(mainSizer);

    datePicker = new wxDatePickerCtrl(this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition,
                                      wxDefaultSize, wxDP_DEFAULT | wxDP_SHOWCENTURY);
    mainSizer->Add(datePicker, 1, wxEXPAND | wxALL, 5);

    wxStdDialogButtonSizer* buttonSizer = CreateStdDialogButtonSizer(wxOK | wxCANCEL);
    if (buttonSizer) {
        mainSizer->Add(buttonSizer, 0, wxALIGN_RIGHT | wxALL, 10);
    }
}

wxDatePickerCtrl *DateSelectionDialog::getDatePicker() const {
    return datePicker;
}

void DateSelectionDialog::setDatePicker(wxDatePickerCtrl *datePicker) {
    DateSelectionDialog::datePicker = datePicker;
}
