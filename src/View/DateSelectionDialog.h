//
// Created by cappe on 22/12/23.
//

#ifndef TODOLIST_DATESELECTION_H
#define TODOLIST_DATESELECTION_H

#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>


class DateSelectionDialog : public wxDialog {

public:
    DateSelectionDialog(wxWindow* parent, const wxString& title);
    wxDatePickerCtrl* getDatePicker() const;
    void setDatePicker(wxDatePickerCtrl *datePicker);

    private:
    //voglio dare un valore di default a datePicker

    wxDatePickerCtrl* datePicker;

};


#endif //TODOLIST_DATESELECTION_H
