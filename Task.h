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

enum class Priority{
    Low,
    Medium,
    High
};


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


private:
    wxDateTime expirationDate;
    wxString title;
    Priority priority;
    bool completed;

};
#endif //TODOLIST_TASK_H
