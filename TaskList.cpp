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
    return listTasks;
}

void TaskList::addList(const wxString& name) {


//    std::vector<std::vector<Task>> listLists; //elenco delle liste di task
//    std::vector<Task> listTasks;
    TaskList newList;
    newList.setName(name);

    //come si stampano le liste di task? un'altra lista?


    //bool sortLists(); //todo da implementare? ci serve qualcosa che le metta in ordine?

}

void TaskList::removeTask(size_t index) {
    if (index < listTasks.size()) {
        listTasks.erase(listTasks.begin() + index);
    }
}


void TaskList::sortLists() {
    std::sort(listTasks.begin(), listTasks.end(), [](const Task& a, const Task& b) {
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

    for (const Task& task : listTasks) {
        // Customize the search logic here based on your criteria
        if (task.getTitle().Lower().Contains(keyword.Lower())) {
            //searchResults.push_back(tasks);
        }
    }

    return searchResults;
}
