//
// Created by cappe on 03/10/23.
//

#ifndef TODOLIST_TODOLISTAPP_H
#define TODOLIST_TODOLISTAPP_H

#include <wx/wx.h>



#include "TaskListListController.h"



class ToDoListApp : public wxApp {
public:
    ToDoListApp();
    virtual bool OnInit();

private:
    wxFrame* frame;
};


#endif //TODOLIST_TODOLISTAPP_H
