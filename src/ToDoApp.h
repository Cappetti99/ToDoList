//
// Created by cappe on 13/12/23.
//

#ifndef LOLLO_TODOAPP_H
#define LOLLO_TODOAPP_H

#include <wx/wx.h>

#include "Control/Control.h"
#include "View/View.h"

class ToDoApp : public wxApp {

public:
    ToDoApp();

    virtual bool OnInit(Model *m, Control *c);

};


#endif //LOLLO_TODOAPP_H
