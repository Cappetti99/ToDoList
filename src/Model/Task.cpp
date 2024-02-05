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

wxString Task::getTitle() {
    return title;
}

Priority Task::getPriority() {
    return priority;
}

wxDateTime Task::getExpirationDate() {
    return expirationDate;
}

bool Task::isCompleted() {
    return completed;
}

void Task::setCompleted(bool completed) {
    this->completed = completed;
}

void Task::setTitle(const wxString &title) {
    this->title = title;
}

void Task::setPriority(Priority priority) {
    this->priority = priority;
}

void Task::setExpirationDate(const wxDateTime &expirationDate) {
    this->expirationDate = expirationDate;
}


