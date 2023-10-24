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
    TaskList(const wxString& name = "");

    const wxString& getName() const;
    void setName(const wxString& name);

    const std::vector<Task>& getTasks() const;
    void addList(const Task& task);
    void removeTask(size_t index);

    void sortTasks();
    std::vector<Task> searchTasks(const wxString& keyword) const;
//SOLO PER PROVARE SE FUNZIONA
    void addTask1(wxDateTime expirationDate, wxString title, Priority selectedPriority);

private:
    //PER PROVA
    std::vector<Task> taskList;

    wxString name;
    std::vector<Task> tasks;
    bool tasksSorted;
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
