//
// Created by cappe on 30/10/23.
//

#ifndef TODOLIST_TASKLISTLIST_H
#define TODOLIST_TASKLISTLIST_H

#include "TaskList.h"


class TaskListList {

public:
    TaskListList();
    std::vector<TaskList>* & addList( wxString& name);

private:
    std::vector<TaskList>* listLists;
    std::vector<int>* a;
};


#endif //TODOLIST_TASKLISTLIST_H
