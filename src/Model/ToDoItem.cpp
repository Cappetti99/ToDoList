//
// Created by cappe on 13/12/23.
//

#include "ToDoItem.h"

//todo da pensare come collegare la task qui con quella che facciamo vedere nel frame

ToDoItem::ToDoItem() {

//    addTask(name, date, priority);
}

void ToDoItem::addTask(wxString name, wxDateTime date, Priority priority) {

    bool isCompleted = false;

    auto task = new Task(name, priority, isCompleted, date) ;

    tasks.push_back(*task);

    std::cout << "item created" << std::endl;
}

void ToDoItem::removeTask(int index) {

    std::cout << "tasks.size =" << tasks.size()<< std::endl;
    std::cout << "index =" << index << std::endl;
    if (tasks.size() >= index + 1) {
        tasks.erase(tasks.begin() + index);
    } else {
        std::cout << "gay" << std::endl; //ci entra quando è vuota
    }

    std::cout << "ToDoItem::removeTask() - tasks.size() = " << tasks.size() << std::endl;
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