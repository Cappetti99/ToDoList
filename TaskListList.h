//
// Created by cappe on 30/10/23.
//

#ifndef TODOLIST_TASKLISTLIST_H
#define TODOLIST_TASKLISTLIST_H

#include "TaskList.h"


class TaskListList {

public:
    TaskListList();

    void addToList(const TaskList list);

private:
    std::vector<TaskList> listLists; //elenco delle liste di task

};


#endif //TODOLIST_TASKLISTLIST_H
