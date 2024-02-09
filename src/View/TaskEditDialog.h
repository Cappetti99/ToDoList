//
// Created by cappe on 05/02/24.
//

#ifndef TODOLIST_TASKEDITDIALOG_H
#define TODOLIST_TASKEDITDIALOG_H

#include <wx/wx.h>
#include <wx/event.h>
#include <wx/gtk/dialog.h>
#include <wx/datectrl.h>
#include "Priority.h"

class TaskEditDialog : public wxDialog {
public:
    TaskEditDialog(wxWindow *parent, const wxString &title, const wxString &taskTitle, const wxDateTime &expirationDate,
                   Priority priority);

    wxString getTaskTitle();

    wxDateTime getExpirationDate();

    Priority getPriority();

private:
    wxTextCtrl *taskTextCtrl;
    wxDatePickerCtrl *expirationDatePicker;
    wxChoice *priorityChoice;
    wxString editedTaskTitle;

    wxButton *okButton;
    wxButton *cancelButton;

    wxDateTime editedExpirationDate;
    Priority editedPriority;

    void OnOK(wxCommandEvent &event);

    void OnCancel(wxCommandEvent &event);

wxDECLARE_EVENT_TABLE();
};


#endif //TODOLIST_TASKEDITDIALOG_H
