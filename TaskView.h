//
// Created by cappe on 22/09/23.
//

#ifndef TODOLIST_TASKVIEW_H
#define TODOLIST_TASKVIEW_H

#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/listctrl.h>
#include <vector>
#include <wx/richtext/richtextctrl.h>
#include <wx/colour.h>
#include <wx/textctrl.h>

#include "Task.h"

class TaskView : public wxFrame {

public:
    TaskView(const wxString& title, const wxPoint& pos, const wxSize& size); //costruttore
    ~TaskView(); //distruttore, ci serve?

private:
    //funzioni
    void editButton(wxCommandEvent& event);

    //variabili
    wxFrame frameTask;
    wxListBox task;

};

//todo da implementare tutte le funzioni


#endif //TODOLIST_TASKVIEW_H
