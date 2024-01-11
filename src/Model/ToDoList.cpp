//
// Created by cappe on 13/12/23.
//

#include "ToDoList.h"

ToDoList::ToDoList() {



}

std::vector<ToDoItem>* ToDoList::getItems() {
    return &this->items;
}

void ToDoList::addItem(ToDoItem item) {
    //this->items.push_back(item);
}

void ToDoList::removeItem(int index) {
    //this->items.erase(this->items.begin() + index);
}

void ToDoList::markItemAsCompleted(int index) {
    //this->items[index].setIsCompleted(true);
}

