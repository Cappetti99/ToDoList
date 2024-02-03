//
// Created by cappe on 18/12/23.
//

#ifndef TODOLIST_ITEMCONTROLLER_H
#define TODOLIST_ITEMCONTROLLER_H

#include <wx/wx.h>
#include <iostream>

#include "Control.h"
#include "../Model/ToDoItem.h"


class ItemController : public Control {

public:
    explicit ItemController(ToDoItem *m);

    ~ItemController() override;

    //metodi di control
    void addTask(wxString name, wxDateTime date, Priority priority) override;

    void removeTask() override;

    void searchTask() override;

    void markAsCompleted(int index) override;


private:
    ToDoItem *toDoItem;

};


#endif //TODOLIST_ITEMCONTROLLER_H
