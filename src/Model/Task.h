//
// Created by cappe on 29/12/23.
//

#ifndef TODOLIST_TASK_H
#define TODOLIST_TASK_H

#include <wx/wx.h>
#include "../View/Priority.h"

class Task {

public:
    Task(const wxString &title = "", Priority priority = Priority::Low,
         bool completed = false, const wxDateTime &expirationDate = wxDateTime::Now());

    wxString getTitle();

    Priority getPriority();

    wxDateTime getExpirationDate();

    bool isCompleted();

    void setCompleted(bool completed);

    void setTitle(const wxString &title);

    void setPriority(Priority priority);

    void setExpirationDate(const wxDateTime &expirationDate);

private:
    wxString title;
    Priority priority;
    bool completed;
    wxDateTime expirationDate;

};


#endif //TODOLIST_TASK_H
