//
// Created by cappe on 22/09/23.
//

#ifndef TODOLIST_TASKLIST_H
#define TODOLIST_TASKLIST_H

#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/listctrl.h>
#include <vector>
#include <wx/richtext/richtextctrl.h>
#include <wx/colour.h>
#include <wx/textctrl.h>
#include <wx/dateevt.h>
#include <wx/textdlg.h>
#include <wx/arrstr.h>


#include "Task.h"


class TaskList {
public:
    TaskList();

private:
    //funzioni
    void addTask();
    void removeTask();
    void sortTask();
    std::vector<Task> searchTask();
    void swapTask();
    void addList();
    void removeList();
    void searchList(); //non dovrebbe ritornare una stringa?
    void renameList();


    //variabili
    std::vector<Task> tasks;

    wxTextCtrl* taskTextCtrl;
    wxTextCtrl* searchInput;
    wxCheckListBox* taskCheckBox;
    wxCheckListBox* searchCheckBox;


};


enum {
    ID_AddTask = wxID_HIGHEST + 1,
    ID_EditTask,
    ID_DeleteTask,
    ID_Check,
    ID_Search
};


//todo aggiunta dei bottoni


#endif //TODOLIST_TASKLIST_H
