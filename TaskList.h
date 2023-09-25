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

};

//todo aggiunta dei bottoni


#endif //TODOLIST_TASKLIST_H
