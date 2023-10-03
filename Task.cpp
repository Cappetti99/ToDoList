#include "Task.h"

Task::Task(const wxString& title, Priority priority, bool completed, const wxDateTime& expirationDate)
        : title(title), priority(priority), completed(completed), expirationDate(expirationDate) {}

// Implement getter and setter methods for Task attributes
const wxString& Task::getTitle() const {
    return title;
}

void Task::setTitle(const wxString& title) {
    this->title = title;
}

Priority Task::getPriority() const {
    return priority;
}

void Task::setPriority(Priority priority) {
    this->priority = priority;
}

bool Task::isCompleted() const {
    return completed;
}

void Task::setCompleted(bool completed) {
    this->completed = completed;
}

const wxDateTime& Task::getExpirationDate() const {
    return expirationDate;
}

void Task::setExpirationDate(const wxDateTime& expirationDate) {
    this->expirationDate = expirationDate;
}

// Static method to convert Priority enum to string
wxString Task::PriorityToString(Priority priority) {
    switch (priority) {
        case Priority::Low:
            return "Low";
        case Priority::Medium:
            return "Medium";
        case Priority::High:
            return "High";
        default:
            return "";
    }
}
