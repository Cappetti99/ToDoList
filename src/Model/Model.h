//
// Created by cappe on 15/12/23.
//

#ifndef LOLLO_MODEL_H
#define LOLLO_MODEL_H

#include <wx/wx.h>

#include "../Model/ToDoList.h"


//il model contiene solo i dati

class Model {

public:
    Model();

    void addTask();
    void removeTask();
    void searchTask();
};


#endif //LOLLO_MODEL_H
