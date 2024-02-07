//
// Created by cappe on 01/02/24.
//

#ifndef TODOLIST_VIEW_H
#define TODOLIST_VIEW_H


#include "../Model/Model.h"
#include "../Control/Control.h"
#include "../Observer.h"

class View : public Observer {

public:

    virtual ~View() ;

    virtual void show() = 0;

};


#endif //TODOLIST_VIEW_H
