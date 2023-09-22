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

private:
    wxDateTime expirationDate;
    wxString title;
    Priority priority;
    bool completed;


public:
    Task(); //costruttore

    const wxDateTime &getExpirationDate() const;

    void setExpirationDate(const wxDateTime &expirationDate);

    const wxString &getTitle() const;

    void setTitle(const wxString &title);

    Priority getPriority() const;

    void setPriority(Priority priority);

    bool isCompleted() const;

    void setCompleted(bool completed);

};
#endif //TODOLIST_TASK_H
