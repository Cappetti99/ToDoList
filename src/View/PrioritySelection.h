//
// Created by cappe on 22/12/23.
//

#ifndef LOLLO_PRIORITYSELECTION_H
#define LOLLO_PRIORITYSELECTION_H

#include <wx/wx.h>

#include "Priority.h"


class PrioritySelection : public wxDialog {

public:
    PrioritySelection(wxWindow* parent, const wxString& title);

    Priority getSelectedPriority() const;

private:
    wxRadioButton *lowButton;
    wxRadioButton *mediumButton;
    wxRadioButton *highButton;

    wxButton *okButton;
    wxButton *cancelButton;

    Priority selectedPriority;

    void OnOK(wxCommandEvent &event);

    void OnCancel(wxCommandEvent &event);

wxDECLARE_EVENT_TABLE();
};


#endif //LOLLO_PRIORITYSELECTION_H
