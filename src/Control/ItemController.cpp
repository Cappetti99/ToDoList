//
// Created by cappe on 18/12/23.
//

#include "ItemController.h"

ItemController::ItemController(TaskList *m) {
    this->model = m;
}

ItemController::~ItemController() {
    delete model;
}

void ItemController::addTask(wxString name, wxDateTime date, Priority priority) {
    bool completed = false;
    model->addTask(name, date, priority, completed);
}

void ItemController::removeTask(int index) {

    model->removeTask(index);
}

std::vector<Task> ItemController::searchTask(wxString word) {

    std::vector<Task> temp;
    for (int i = 0; i < model->getVector().size(); i++) {
        wxString taskName = model->getVector()[i].getTitle();
        if (taskName.Contains(word)) {
            temp.push_back(model->getVector()[i]);
        }
    }
    return temp;
}

void ItemController::markAsCompleted(int index) {

    model->setTaskAsCompleted(index);
}

void ItemController::editTask(int index, wxString name, wxDateTime date, Priority priority) {

    model->editTask(index, name, date, priority);
}
