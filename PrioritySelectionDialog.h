//
// Created by cappe on 11/10/23.
//

#ifndef TODOLIST_PRIORITYSELECTIONDIALOG_H
#define TODOLIST_PRIORITYSELECTIONDIALOG_H


#include <wx/wx.h>

#include "Priority.h"



class PrioritySelectionDialog : public wxDialog {
public:
    PrioritySelectionDialog(wxWindow* parent, const wxString& title);

    Priority getSelectedPriority() const;

private:
    wxRadioButton* lowButton;
    wxRadioButton* mediumButton;
    wxRadioButton* highButton;

    wxButton* okButton;
    wxButton* cancelButton;

    Priority selectedPriority;

    void OnOK(wxCommandEvent& event);
    void OnCancel(wxCommandEvent& event);

wxDECLARE_EVENT_TABLE();

};


#endif //TODOLIST_PRIORITYSELECTIONDIALOG_H
