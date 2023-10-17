//
// Created by cappe on 22/09/23.
//

#ifndef TODOLIST_TASK_H
#define TODOLIST_TASK_H

#include <wx/wx.h>
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <algorithm>
#include <wx/datetime.h>
#include <wx/datectrl.h>

//#include "DateSelectionDialog.h"
//#include "PrioritySelectionDialog.h"
//#include "TaskListListView.h"

#include "Priority.h"

class Task {

public:
    Task(const wxString& title = "", Priority priority = Priority::Low,
         bool completed = false, const wxDateTime& expirationDate = wxDateTime::Now());

    // Getter and setter methods for Task attributes
    const wxString& getTitle() const;
    void setTitle(const wxString& title);

    Priority getPriority() const;
    void setPriority(Priority priority);

    bool isCompleted() const;
    void setCompleted(bool completed);

    const wxDateTime& getExpirationDate() const;
    void setExpirationDate(const wxDateTime& expirationDate);

    // Static method to convert Priority enum to string
    static wxString PriorityToString(Priority priority);

    void addTask(wxDateTime expirationDate, wxString title, Priority selectedPriority);
    void removeTask();
    void sortTask();
    std::vector<Task> searchTask();
    void swapTask();
    void refreshTask();

private:
    wxDateTime expirationDate;
    wxString title;
    Priority priority;
    bool completed;
    std::vector<Task> taskList;

};
#endif //TODOLIST_TASK_H
