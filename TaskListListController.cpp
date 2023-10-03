//
// Created by cappe on 22/09/23.
//

#include "TaskListListController.h"

TaskListListController::TaskListListController(std::vector<TaskList>& models, TaskListListView& view)
        : models(models), view(view) {}

void TaskListListController::addList(const TaskList& taskList) {
    models.push_back(taskList);
    // Update the view to reflect the changes
    // For example, refresh the task list box in the view.
}

void TaskListListController::removeList(size_t index) {
    if (index < models.size()) {
        models.erase(models.begin() + index);
        // Update the view to reflect the changes
    }
}

void TaskListListController::searchList(const wxString& searchTerm) {
    // Implement search logic here, based on list names or other criteria.
    // Create a vector of matching lists and update the view.
}

void TaskListListController::renameList(const wxString& newName) {
    // Implement logic to rename a list and update the view.
    // You may need to find the correct list by index and update its name.
}
