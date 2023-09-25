//
// Created by cappe on 22/09/23.
//

#ifndef TODOLIST_TASKLISTLISTCONTROLLER_H
#define TODOLIST_TASKLISTLISTCONTROLLER_H


#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/listctrl.h>
#include <vector>
#include <wx/richtext/richtextctrl.h>
#include <wx/colour.h>
#include <wx/textctrl.h>

#include "Task.h"

class TaskListListController {

public:
    TaskListListController();

private:
    std::vector<Task> tasks;

};

//todo c'è da implementare il costruttore?


#endif //TODOLIST_TASKLISTLISTCONTROLLER_H
