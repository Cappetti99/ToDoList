//
// Created by cappe on 22/12/23.
//

#include "DateSelection.h"

DateSelection::DateSelection(wxWindow *parent, const wxString &title)
        : wxDialog(parent, wxID_ANY, title, wxDefaultPosition, wxDefaultSize) {

    auto mainSizer = new wxBoxSizer(wxVERTICAL);
    SetSizer(mainSizer);

    datePicker = new wxDatePickerCtrl(this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition,
                                      wxDefaultSize, wxDP_DEFAULT | wxDP_SHOWCENTURY);
    mainSizer->Add(datePicker, 1, wxEXPAND | wxALL, 5);

    wxStdDialogButtonSizer *buttonSizer = CreateStdDialogButtonSizer(wxOK | wxCANCEL);

    mainSizer->Add(buttonSizer, 0, wxALIGN_RIGHT | wxALL, 10);


    //fixme quando annullo inserisce comunque la task, non a schermo perchè le due cose non sono collegate

}

wxDatePickerCtrl *DateSelection::getDatePicker() const {
    return datePicker;
}

void DateSelection::setDatePicker(wxDatePickerCtrl *datePicker) {
    this->datePicker = datePicker;
}
