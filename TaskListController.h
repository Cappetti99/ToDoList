//
// Created by cappe on 22/09/23.
//

#ifndef TODOLIST_TASKLISTCONTROLLER_H
#define TODOLIST_TASKLISTCONTROLLER_H

#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/listctrl.h>
#include <vector>
#include <wx/richtext/richtextctrl.h>
#include <wx/colour.h>
#include <wx/textctrl.h>

#include "Task.h"
#include "TaskList.h"
#include "TaskView.h"

class TaskListController {

public:
    TaskListController();

private:
    //funzioni
    void addTask();
    void removeTask();
    std::vector<Task> searchTask();
    void sortTask();
    void swapList();
    void addList();
    void removeList();
    void searchList();
    void renameList();

    //variabili
    TaskList model;  //non ricordo a che serve
    TaskView view;  //non ricordo a che serve

};


#endif //TODOLIST_TASKLISTCONTROLLER_H
