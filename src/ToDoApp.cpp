//
// Created by cappe on 13/12/23.
//

#include "ToDoApp.h"

bool ToDoApp::OnInit() {

    auto toDoItem = new ToDoItem();
    auto itemController = new ItemController(toDoItem);
    auto frame = new Frame(toDoItem, itemController, "ToDoList", wxPoint(50, 50), wxSize(450, 340));
    frame->show();
    return true;

}

wxIMPLEMENT_APP(ToDoApp);

