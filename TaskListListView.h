//
// Created by cappe on 22/09/23.
//

#ifndef TODOLIST_TASKLISTLISTVIEW_H
#define TODOLIST_TASKLISTLISTVIEW_H

#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/listctrl.h>
#include <vector>
#include <wx/richtext/richtextctrl.h>
#include <wx/colour.h>
#include <wx/textctrl.h>
#include <wx/listbox.h>

#include "CustomWindow.h"
#include "TaskList.h"
#include "ToDoListApp.h"


class TaskListListView : public wxFrame {

public:
    TaskListListView(const wxString& title, const std::vector<TaskList>& taskLists);

private:
    /*
    //funzioni
    void addListButton(wxCommandEvent& event);
    void removeListButton(wxCommandEvent& event);
    void searchListButton(wxCommandEvent& event);
    void renameListButton(wxCommandEvent& event);
    void openListButton(wxCommandEvent& event);
*/

    //variabili
    wxFrame frameListList;
    wxListBox taskListList;

    std::vector<TaskList> taskLists;
    wxListBox* taskListListBox;

    //bottoni
    wxButton* addListButton;
    wxButton* removeListButton;
    wxButton* searchListButton;
    wxButton* renameListButton;

};

//todo quando premo un tasto deve andare da qualche parte, da fare questo


#endif //TODOLIST_TASKLISTLISTVIEW_H