//
// Created by cappe on 01/02/24.
//

#include "View.h"

View::View(Model *m, Control *c) {
    model = m;
//    model->addObserver(this);
    control = c;
}

View::~View() {

//    model->removeObserver(this);

}

void View::show() {

    std::cout << "View show" << std::endl;
    frame = new Frame("ToDoApp", wxDefaultPosition, wxSize(450, 340));
    std::cout << "Frame created" << std::endl;
    frame->Show(true);

}

void View::update() {

    //TODO: update view
    //deve pulire la schermata e riscriverla

    std::cout << "View updated" << std::endl;

}



