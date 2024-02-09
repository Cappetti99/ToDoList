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

    auto task = new Task(name, priority, isCompleted, date);

    tasks.push_back(*task);

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
    if (tasks[index].isCompleted() == false) {
        tasks[index].setCompleted(true);
    } else {
        tasks[index].setCompleted(false);
    }
    //se io ritornassi un bool, potrei fare un if e dire che se è true allora metto il check, altrimenti no
}

bool ToDoItem::getCompleted(int index) {
    return tasks[index].isCompleted();
}

std::vector<Task> ToDoItem::getImportantTask() {
    std::vector<Task> important;
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].getPriority() == Priority::High) {
            important.push_back(tasks[i]);
        }
    }
    return important;
}
std::vector<Task> ToDoItem::getExpiringTask(){
    std::vector<Task> expiring;
    wxDateTime data = data.Today();
    std::vector<Task> b= tasks;
    for(int i =0; i<tasks.size();i++){
        if(tasks[i].getExpirationDate().GetDay()== data.GetDay()){
            expiring.push_back(tasks[i]);
        }
    }
    return expiring;
};