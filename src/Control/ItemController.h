//
// Created by cappe on 18/12/23.
//

#ifndef TODOLIST_ITEMCONTROLLER_H
#define TODOLIST_ITEMCONTROLLER_H

#include <wx/wx.h>
#include <iostream>

#include "Control.h"
#include "../Model/TaskList.h"


class ItemController : public Control {

public:
    ItemController(TaskList *m);

    ~ItemController() override;

    //metodi di control
    void addTask(wxString name, wxDateTime date, Priority priority) override;

    void removeTask(int index) override;

    void markAsCompleted(int index) override;

    void editTask(int index, wxString name, wxDateTime date, Priority priority) override;

    std::vector<Task> searchTask(wxString word);

    void sortByPriority();

    void sortByDate();

    void sortByAlphabet();

private:
    TaskList *model;

};


#endif //TODOLIST_ITEMCONTROLLER_H
