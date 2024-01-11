//
// Created by cappe on 29/12/23.
//

#ifndef LOLLO_TASK_H
#define LOLLO_TASK_H

#include <wx/wx.h>
#include "../View/Priority.h"

class Task {

public:
    Task(const wxString &title = "", Priority priority = Priority::Low,
         bool completed = false, const wxDateTime &expirationDate = wxDateTime::Now());


    const wxString getTitle() const;

    const Priority getPriority() const;

    const wxDateTime getExpirationDate() const;






private:
    wxString title;
    Priority priority;
    bool completed;
    wxDateTime expirationDate;


};


#endif //LOLLO_TASK_H
