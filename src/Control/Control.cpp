//
// Created by cappe on 13/12/23.
//

#include "Control.h"

Control::Control() {

    std::cout << "Control created" << std::endl;

    auto itemController = new ItemController();
    auto listController = new ListController();
}

void Control::addTask(wxString name, wxDateTime date, Priority priority) {

    std::cout << "Control::addTask()" << std::endl;
    ItemController itemController;
    itemController.addItem(name, date, priority);


}

void Control::removeTask() {

    std::cout << "Control::removeTask()" << std::endl;

}

void Control::searchTask() {

    std::cout << "Control::searchTask()" << std::endl;
}

void Control::markAsCompleted() {

    std::cout << "Control::markAsCompleted()" << std::endl;
}

void Control::updateView() {

    std::cout << "Control::updateView()" << std::endl;
}
