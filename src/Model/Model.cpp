//
// Created by cappe on 01/02/24.
//

#include "Model.h"

void Model::addObserver(Observer *o) {

    observers.push_back(o);

}

void Model::removeObserver(Observer *o) {

    observers.remove(o);

}

void Model::notify() {

    for (auto &observer: observers) {
        observer->update();
    }

}

void Model::addTask(wxString title, wxDateTime date, Priority priority) {

    ToDoItem *item = new ToDoItem();
    item->addTask(title, date, priority);

    notify();
}

