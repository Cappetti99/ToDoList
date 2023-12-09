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
    TaskList( wxString& name);

    wxString getName() const;


    std::vector<Task> &addTask(wxDateTime expirationDate, wxString title, Priority selectedPriority);
    void removeTask(size_t index);

    void sortLists();
    std::vector<Task> searchTasks(const wxString& keyword) const;


private:
    wxString title;
    //std::vector<TaskList> listLists; //elenco delle liste di task
    std::vector<Task> listTasks;

    //bool tasksSorted;
};

/*
enum {
    ID_AddTask = wxID_HIGHEST + 1,
    ID_EditTask,
    ID_DeleteTask,
    ID_Check,
    ID_Search
};
*/

//todo aggiunta dei bottoni


#endif //TODOLIST_TASKLIST_H
