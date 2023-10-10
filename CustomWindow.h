//
// Created by cappe on 27/09/23.
//

#ifndef TODOLIST_CUSTOMWINDOW_H
#define TODOLIST_CUSTOMWINDOW_H

#include <wx/wx.h>
#include <wx/textctrl.h>

#include "TaskListListView.h"


class CustomWindow : public wxFrame {
public:
    CustomWindow(wxWindow* parent, const wxString& title, const wxPoint& pos, const wxSize& size);
    void Windows1();
    void Windows2();

private:
    wxBoxSizer* mainSizer;
};

#endif //TODOLIST_CUSTOMWINDOW_H
