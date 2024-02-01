//
// Created by cappe on 13/12/23.
//

#include "ToDoApp.h"
#include "View/View.h"

ToDoApp::ToDoApp() {

    std::cout << "App created" << std::endl;

}


bool ToDoApp::OnInit(Model *model, Control *control) {

    auto view = new View(model, control);
    view->show();
    return true;

}

//wxIMPLEMENT_APP(ToDoApp);

