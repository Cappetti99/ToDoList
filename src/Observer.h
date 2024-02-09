//
// Created by cappe on 01/02/24.
//

#ifndef TODOLIST_OBSERVER_H
#define TODOLIST_OBSERVER_H


class Observer {

public:
    virtual void update() = 0;
    virtual ~Observer();
};


#endif //TODOLIST_OBSERVER_H
