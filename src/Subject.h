//
// Created by cappe on 01/02/24.
//

#ifndef TODOLIST_SUBJECT_H
#define TODOLIST_SUBJECT_H

#include "Observer.h"

class Subject {

public:
    virtual ~Subject();

    virtual void notify() = 0;
    virtual void addObserver(Observer *o) = 0;
    virtual void removeObserver(Observer *o) = 0;

};


#endif //TODOLIST_SUBJECT_H
