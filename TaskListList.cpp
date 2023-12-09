
//
// Created by cappe on 30/10/23.
//

#include "TaskListList.h"


TaskListList::TaskListList() {
    //listLists = std::vector<TaskList>();
    a=new std::vector<int>();
    int b =9;
    a->push_back(b);
    listLists = new std::vector<TaskList>();
}

std::vector<TaskList>* &TaskListList:: addList( wxString& name) {

    //listLists= std::vector<TaskList *> listLists;
    TaskList newlist(name);

    listLists->push_back(newlist);
    return listLists;
}
//non  credo serva il get

//listLists.push_back(*new TaskList(name));