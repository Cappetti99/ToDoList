//
// Created by cappe on 22/09/23.
//

#include "Task.h"

Task::Task() : priority(Priority::Low){}

const wxDateTime &Task::getExpirationDate() const {
    return expirationDate;
}

void Task::setExpirationDate(const wxDateTime &expirationDate) {
    Task::expirationDate = expirationDate;
}

const wxString &Task::getTitle() const {
    return title;
}

void Task::setTitle(const wxString &title) {
    Task::title = title;
}

Priority Task::getPriority() const {
    return priority;
}

void Task::setPriority(Priority priority) {
    Task::priority = priority;
}

bool Task::isCompleted() const {
    return completed;
}

void Task::setCompleted(bool completed) {
    Task::completed = completed;
}

