//
// Created by cappe on 18/12/23.
//

#include "ItemController.h"


ItemController::ItemController() {

    frame = new Frame("ToDoList", wxDefaultPosition, wxSize(450, 340), this);
    frame->Show(true);

    item = new ToDoItem();

}

void ItemController::onAddTaskButtonClicked() {

    //std::cout << "ItemController::onAddTaskButtonClicked()" << std::endl;

    addItem(frame->getNome(), frame->getData(), frame->getPriorità());
    //probabilmente potremmo fare tutto qui, senza passare da un'altra funzione

}

void ItemController::addItem(wxString name, wxDateTime date, Priority priority) {

    //std::cout << "ItemController::addItem()" << std::endl;
    item->addTask(name, date, priority);
    std::vector<Task> temp =item->getVector();
    std::sort(temp.begin(), temp.end(),
              [](const Task &a, const Task &b) {
                  return a.getExpirationDate() < b.getExpirationDate();
              });
    std::sort(temp.begin(), temp.end(),
              [](const Task &a, const Task &b) {
                  return a.getPriority() > b.getPriority();
              });
    item->tasks=temp;
    showTask(temp);

}

void ItemController::showTask(std::vector<Task> pippo) {
    frame->ClearFrame();
    for (int i=0; i<pippo.size(); i++){

    frame->showTaskFrame(item->getName(i), item->getDate(i), item->getPriority(i));
}
    //farla vedere sul frame


}

void ItemController::onRemoveTaskButtonClicked(int index) {

    //std::cout << "ItemController::onRemoveTaskButtonClicked()" << std::endl;

    removeItem(index);

}

void ItemController::removeItem(int index) {

    //std::cout << "ItemController::removeItem()" << std::endl;
    //wxString name = item->getName(index);
    item->removeTask(index); //todo da cambiare perchè elimina per indice e non per nome
    showTask(item->getVector());

    //removeFrame(index);
}

void ItemController::removeFrame(int index) {

   // showTask(item->getVector());
}

void ItemController::onSearchTaskButtonClicked(wxString searchKeyword) {

//    std::cout << "ItemController::onSearchTaskButtonClicked()" << std::endl;

    searchItem(searchKeyword);

}

void ItemController::markItemAsCompleted() {

}

void ItemController::searchItem(wxString searchKeyword) {

//    frame->ClearFrame();
    std::vector<Task*> tasks;
    std::vector<wxString> namesSearch;
    std::vector<wxDateTime> datesSearch;
    std::vector<Priority> prioritiesSearch;

    for(int i = 0; i < item->getVector().size(); i++) {
        wxString taskName = item->getName(i);
        if (taskName.Find(searchKeyword) != wxNOT_FOUND) {
            tasks.push_back(&item->tasks[i]);
            namesSearch.push_back(item->getName(i));
            datesSearch.push_back(item->getDate(i));
            prioritiesSearch.push_back(item->getPriority(i));
//            frame->showSearchFrame(item->getName(i), item->getDate(i), item->getPriority(i));
        }
    }
    if(tasks.size() > 0) {
        frame->showSearchFrame(namesSearch, datesSearch, prioritiesSearch);
    } //gestire il caso in cui non ci siano task che contengono la keyword


//    for (int i = 0; i < tasks.size(); ++i) {
//        wxString taskName = item->getName(i);
//
//        if (taskName.Find(searchKeyword) != wxNOT_FOUND) {
//            wxDateTime taskDate = item->getDate(i);
//            Priority taskPriority = item->getPriority(i);
//            frame->showSearchFrame(taskName, taskDate, taskPriority);
//        }
//    }
}


