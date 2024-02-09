//
// Created by cappe on 13/12/23.
//

#include "TaskList.h"


TaskList::TaskList() = default;

TaskList::~TaskList() {
    for (auto &task: tasks) {
        delete &task;
    }
}

void TaskList::addTask(wxString name, wxDateTime date, Priority priority, bool completed) {

    auto task = new Task(name, priority, completed, date);
    tasks.push_back(*task); //ho creato una task e ora la metto nel vettore di task
    std::sort(tasks.begin(), tasks.end(), comparePriority);

    notify();
}

void TaskList::removeTask(int index) {

    if (tasks.size() >= index + 1) {
        tasks.erase(tasks.begin() + index);
    }
    notify();
}

void TaskList::notify() {

    for (auto &observer: observers) {
        observer->update();
    }
}

void TaskList::addObserver(Observer *o) {
    observers.push_back(o);
}

void TaskList::removeObserver(Observer *o) {
    observers.remove(o);
}

std::vector<Task> TaskList::getVector() {
    return tasks;
}

void TaskList::setTaskAsCompleted(int index) {
    if (!tasks[index].isCompleted()) {
        tasks[index].setCompleted(true);
    } else {
        tasks[index].setCompleted(false);
    }

    notify();
}

void TaskList::editTask(int index, wxString name, wxDateTime date, Priority priority) {

    tasks[index].setTitle(name);
    tasks[index].setExpirationDate(date);
    tasks[index].setPriority(priority);

    std::sort(tasks.begin(), tasks.end(), comparePriority);

    notify();

}

void TaskList::sortByPriority() {
    std::sort(tasks.begin(), tasks.end(), comparePriority);
    notify();
}

bool TaskList::comparePriority(Task a, Task b) {
    return a.getPriority() > b.getPriority();
}

void TaskList::sortByDate() {
    std::sort(tasks.begin(), tasks.end(), compareDate);
    notify();
}

bool TaskList::compareDate(Task a, Task b) {
    return a.getExpirationDate() < b.getExpirationDate();
}

void TaskList::sortByAlphabet() {
    std::sort(tasks.begin(), tasks.end(), compareAlphabet);
    notify();
}

bool TaskList::compareAlphabet(Task a, Task b) {
    return a.getTitle() < b.getTitle();
}


std::vector<Task> TaskList::getImportantTask() {
    std::vector<Task> important;
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].getPriority() == Priority::High) {
            important.push_back(tasks[i]);
        }
    }
    return important;
}
std::vector<Task> TaskList::getExpiringTask(){
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


 int TaskList::completedTask(){
     int numero;
     for(int i =0; i<tasks.size();i++){
         if(tasks[i].isCompleted() == true){
             numero++;
         }
     }
     return numero;
 }