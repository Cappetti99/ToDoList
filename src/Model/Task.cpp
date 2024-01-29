//
// Created by cappe on 29/12/23.
//

#include "Task.h"

Task::Task(const wxString &title, Priority priority, bool completed, const wxDateTime &expirationDate) {

    this->title = title;
    this->priority = priority;
    this->completed = completed;
    this->expirationDate = expirationDate;


}

const wxString Task::getTitle() const {
    return title;
}

const Priority Task::getPriority() const {
    return priority;
}

const wxDateTime Task::getExpirationDate() const {
    return expirationDate;
}

const bool Task::isCompleted() const {
    return completed;
}

void Task::setCompleted(bool completed) {
    this->completed = completed;
}


