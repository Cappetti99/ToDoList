//
// Created by cappe on 13/12/23.
//

#include "ToDoItem.h"


ToDoItem::ToDoItem() {

//    addTask(name, date, priority);
}

void ToDoItem::addTask(wxString name, wxDateTime date, Priority priority) {

    bool isCompleted = false;

    auto task = new Task(name, priority, isCompleted, date);

    tasks.push_back(*task); //ho creato una task e ora la metto nel vettore di task


}

void ToDoItem::removeTask(int index) {


    if (tasks.size() >= index + 1) {
        tasks.erase(tasks.begin() + index);
    }
}

std::vector<Task> ToDoItem::getVector() {
    return tasks;
}

wxString ToDoItem::getName(int index) {
    return tasks[index].getTitle();
}

wxDateTime ToDoItem::getDate(int index) {
    return tasks[index].getExpirationDate();
}

Priority ToDoItem::getPriority(int index) {
    return tasks[index].getPriority();
}

void ToDoItem::setTaskAsCompleted(int index) {
    if(tasks[index].isCompleted() == false) {
        tasks[index].setCompleted(true);
    } else {
        tasks[index].setCompleted(false);
    }
    //se io ritornassi un bool, potrei fare un if e dire che se è true allora metto il check, altrimenti no
}

bool ToDoItem::getCompleted(int index) {
    return tasks[index].isCompleted();
}
