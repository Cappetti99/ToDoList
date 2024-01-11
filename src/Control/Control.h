//
// Created by cappe on 13/12/23.
//

#ifndef LOLLO_CONTROLL_H
#define LOLLO_CONTROLL_H

#include <wx/wx.h>


#include "ItemController.h"
#include "ListController.h"


class Control {

private:
//    Model model;
//    View view; //così facendo entra prima nel costruttore della view e poi nel costruttore del controller, idem con model

public:
    Control();

    static void addTask(wxString name, wxDateTime date, Priority priority);

    static void removeTask();

    static void searchTask();

    void markAsCompleted();

    void updateView();


};


#endif //LOLLO_CONTROLL_H
