/*
#include <wx/wx.h>

#include "TaskListView.h"
#include "TaskListListView.h"
#include "TaskListController.h"
#include "TaskListListController.h"
#include "CustomWindow.h"

class ToDoListApp : public wxApp {
public:
    virtual bool OnInit() {
        // Create TaskList objects and TaskListListView
        std::vector<TaskList> taskLists;
        TaskListListView* listListView = new TaskListListView("ToDo Lists", taskLists);

        // Create controllers for task lists
        TaskListListController listListController(taskLists, *listListView);

        // Create a sample task list and TaskListView
        TaskList sampleList("Sample List");

        new CustomWindow(listListView, "Tasks in Sample List", wxDefaultPosition, wxSize(400, 300));
        TaskListView* taskListView = new TaskListView("Tasks in Sample List", wxPoint(100, 100), wxSize(400, 300));

        // Create controllers for tasks within the sample list
        TaskListController taskListController(sampleList, *taskListView);

        listListView->Show(true);
        taskListView->Show(true);

        return true;
    }
};
*/
