//
// Created by cappe on 22/09/23.
//

#ifndef TODOLIST_TASKLISTVIEW_H
#define TODOLIST_TASKLISTVIEW_H

#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/listctrl.h>
#include <vector>
#include <wx/richtext/richtextctrl.h>
#include <wx/colour.h>
#include <wx/textctrl.h>

#include "Task.h"
#include "CustomWindow.h"
#include "TaskList.h"


class TaskListView : public wxFrame {

public:
    TaskListView(const wxString& title, const wxPoint& pos, const wxSize& size);

private:
    //funzioni

    //fixme
    
   /* void addTaskButton(wxCommandEvent& event);
    void removeTaskButton(wxCommandEvent& event);
    void searchTaskButton(wxCommandEvent& event);
    void moveTaskToAnotherList(wxCommandEvent& event);
    void sortButton(wxCommandEvent& event); */

   //ci servono funzioni o possiamo farli così?:

   /* TaskList taskList;
    wxListBox* taskListBox;
    wxButton* addButton;
    wxButton* removeButton;
    wxButton* sortButton;
    wxButton* searchButton; */

    //variabili
    wxFrame frameList;
    wxListBox taskList;

};

//todo da implementare tutte le funzioni

#endif //TODOLIST_TASKLISTVIEW_H
