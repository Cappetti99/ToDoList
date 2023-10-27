//
// Created by cappe on 22/09/23.
//

#include "TaskList.h"

TaskList::TaskList(const wxString& name)
        : name(name) {

}

const wxString& TaskList::getName() const {
    return name;
}

void TaskList::setName(const wxString& name) {
    this->name = name;
}

const std::vector<Task>& TaskList::getTasks() const {
    return tasks;
}

void TaskList::addList(const wxString& name) {



    TaskList newList(name);

    
}

void TaskList::removeTask(size_t index) {
    if (index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
    }
}


void TaskList::sortTasks() {
    std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        // Implement your comparison logic here
        // For example, you can compare tasks based on their attributes like priority, expiration date, etc.
        // Return true if 'a' should come before 'b' in the sorted order.
        return a.getPriority() < b.getPriority(); // Sort by priority for example
    });

    // Set the tasksSorted flag to true after sorting
    tasksSorted = true;
}

// Implement the searchTasks function in TaskList.cpp
std::vector<Task> TaskList::searchTasks(const wxString& keyword) const {
    std::vector<Task> searchResults;

    for (const Task& task : tasks) {
        // Customize the search logic here based on your criteria
        if (task.getTitle().Lower().Contains(keyword.Lower())) {
            //searchResults.push_back(tasks);
        }
    }

    return searchResults;
}
