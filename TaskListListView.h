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

#include "CustomWindow.h"
#include "TaskList.h"


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

//todo da implementare tutte le funzioni


#endif //TODOLIST_TASKLISTLISTVIEW_H
