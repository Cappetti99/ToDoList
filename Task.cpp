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

void Task::addTask() {

    wxString task = taskTextCtrl->GetValue(); //credo sia sbagliato e si debba prendere da TaskListListView con un get invece di dichiararlo nel .h
    if (!task.IsEmpty()) {
        //DateSelectionDialog dateDialog = new DateSelectionDialog(this, "Select expiration date:");   //fixme da capire cosa scrivere al posto di this
        //PrioritySelectionDialog priorityDialog = new PrioritySelectionDialog(this, "Select priority:");



    }
}

void Task::removeTask(size_t index) {

}

void Task::sortTask() {

}

std::vector<Task> Task::searchTasks() {
    return std::vector<Task>();
}
