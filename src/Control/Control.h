//
// Created by cappe on 13/12/23.
//

#ifndef LOLLO_CONTROLL_H
#define LOLLO_CONTROLL_H

#include <wx/wx.h>

#include "ItemController.h"
#include "../Model/Model.h"


class Control {

public:
    Control(Model *m);

    static void addTask(wxString name, wxDateTime date, Priority priority);

    static void removeTask();

    static void searchTask();

    void markAsCompleted();

//    void updateView();

private:
    Model *model;
    ItemController *itemController;
};


#endif //LOLLO_CONTROLL_H
