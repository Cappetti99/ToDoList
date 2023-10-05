//
// Created by cappe on 27/09/23.
//

#ifndef TODOLIST_CUSTOMWINDOW_H
#define TODOLIST_CUSTOMWINDOW_H

#include <wx/wx.h>
#include "TaskListView.h"
#include "TaskListListView.h"
#include "TaskList.h"


class CustomWindow : public wxFrame {
public:
    CustomWindow(wxWindow* parent, const wxString& title, const wxPoint& pos, const wxSize& size);

private:
    wxBoxSizer* mainSizer;
};

#endif //TODOLIST_CUSTOMWINDOW_H
