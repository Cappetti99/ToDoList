//
// Created by cappe on 30/10/23.
//

#include "TaskListList.h"


TaskListList::TaskListList() {

}

void TaskListList::addToList(const TaskList list) {

    listLists.push_back(list);
}

