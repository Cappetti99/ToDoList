//
// Created by cappe on 01/02/24.
//

#include "Model.h"

Model::~Model(){
    for (auto observer : observers) {
        delete observer;
    }
}