//
// Created by cappe on 13/12/23.
//

#include "ToDoApp.h"

ToDoApp::ToDoApp() {

    std::cout<<"App created"<<std::endl;

}


bool ToDoApp::OnInit() {
//    auto model = new Model();
//    auto view = new View();
    new Control();
    return true;

}

//wxIMPLEMENT_APP(ToDoApp);

