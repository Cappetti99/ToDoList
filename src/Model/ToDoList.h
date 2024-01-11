//
// Created by cappe on 13/12/23.
//

#ifndef LOLLO_TODOLIST_H
#define LOLLO_TODOLIST_H

#include <wx/wx.h>
#include <vector>

#include "ToDoItem.h"

class ToDoList {

private:
    std::vector<ToDoItem> items;

    public:
    ToDoList();
    std::vector<ToDoItem>* getItems();
    static void addItem(ToDoItem item);
    void removeItem(int index);
    void markItemAsCompleted(int index);


    //da pensare le operazioni sulle liste

};


#endif //LOLLO_TODOLIST_H
