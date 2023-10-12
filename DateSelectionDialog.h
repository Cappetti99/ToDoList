//
// Created by cappe on 11/10/23.
//

#ifndef TODOLIST_DATESELECTIONDIALOG_H
#define TODOLIST_DATESELECTIONDIALOG_H

#include <wx/wx.h>
#include <wx/datectrl.h>

class DateSelectionDialog : public wxDialog {
public:

    DateSelectionDialog(wxWindow* parent, const wxString& title);

    wxDatePickerCtrl *getDatePicker() const;

    void setDatePicker(wxDatePickerCtrl *datePicker);

private:

    wxDatePickerCtrl* datePicker;

};


#endif //TODOLIST_DATESELECTIONDIALOG_H
