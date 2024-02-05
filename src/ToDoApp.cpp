//
// Created by cappe on 13/12/23.
//

#include "ToDoApp.h"

bool ToDoApp::OnInit() {

    TaskList* taskList = new TaskList();
    ItemController* itemController = new ItemController(taskList);
    Frame* frame = new Frame(taskList, itemController, "ToDoList", wxPoint(50, 50), wxSize(450, 340));
    frame->show();
    return true;

}

wxIMPLEMENT_APP(ToDoApp);

