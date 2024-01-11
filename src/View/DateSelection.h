//
// Created by cappe on 22/12/23.
//

#ifndef LOLLO_DATESELECTION_H
#define LOLLO_DATESELECTION_H

#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>


class DateSelection : public wxDialog {

public:
    DateSelection(wxWindow* parent, const wxString& title);
    wxDatePickerCtrl* getDatePicker() const;
    void setDatePicker(wxDatePickerCtrl *datePicker);

    private:
    //voglio dare un valore di default a datePicker

    wxDatePickerCtrl* datePicker;

};


#endif //LOLLO_DATESELECTION_H
