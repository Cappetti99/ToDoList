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
    std::sort(tasks.begin(), tasks.end(), compareTasks);

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

bool TaskList::compareTasks(Task a, Task b) {
    return a.getPriority() > b.getPriority();
}

void TaskList::editTask(int index, wxString name, wxDateTime date, Priority priority) {

    tasks[index].setTitle(name);
    tasks[index].setExpirationDate(date);
    tasks[index].setPriority(priority);

    std::sort(tasks.begin(), tasks.end(), compareTasks);

    notify();

}

