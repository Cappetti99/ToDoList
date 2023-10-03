//
// Created by cappe on 03/10/23.
//

#include "ToDoListApp.h"

ToDoListApp::ToDoListApp() {}


bool ToDoListApp::OnInit() {
        // Create TaskList objects and TaskListListView
        std::vector<TaskList> taskLists;
        TaskListListView* listListView = new TaskListListView("ToDo Lists", taskLists);

        // Create controllers for task lists
        TaskListListController listListController(taskLists, *listListView);

        // Create a sample task list and TaskListView
        TaskList sampleList("Sample List");
        TaskListView* taskListView = new TaskListView("Tasks in Sample List", wxPoint(100, 100), wxSize(400, 300));

        // Create controllers for tasks within the sample list
        TaskListController taskListController(sampleList, *taskListView);

        listListView->Show(true);
        taskListView->Show(true);

        return true;
    }

