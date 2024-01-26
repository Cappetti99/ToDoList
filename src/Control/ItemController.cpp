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

void ItemController::showTask(std::vector<Task> vettore) {
    frame->ClearFrame();
    for (int i=0; i<vettore.size(); i++){

        frame->showTaskFrame(item->getName(i), item->getDate(i), item->getPriority(i),item->getCompleted(i),i);
    }

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
    std::vector<bool> compleatedSearch;

    //è brutto quello che sto per fare

    std::vector<wxString> allNames;
    std::vector<wxDateTime> allDates;
    std::vector<Priority> allPriorities;
    std::vector<bool> allCompleated;

    for (int i = 0; i < item->getVector().size(); i++) {
        allNames.push_back(item->getName(i));
        allDates.push_back(item->getDate(i));
        allPriorities.push_back(item->getPriority(i));
        allCompleated.push_back(item->getCompleted(i));
        wxString taskName = item->getName(i);
        if (taskName.Find(searchKeyword) != wxNOT_FOUND) {
            tasks.push_back(&item->tasks[i]);
            namesSearch.push_back(item->getName(i));
            datesSearch.push_back(item->getDate(i));
            prioritiesSearch.push_back(item->getPriority(i));
            compleatedSearch.push_back(item->getCompleted(i));
        }
    }
    if (tasks.size() > 0) {
        frame->showSearchFrame(namesSearch, datesSearch, prioritiesSearch, compleatedSearch, allNames, allDates,
                               allPriorities, allCompleated);
    } //gestire il caso in cui non ci siano task che contengono la keyword

}

void ItemController::onCheckTaskButtonClicked(int index) {

    //con un set si mette a true se era false e viceversa

    std::cout << "ItemController::onCheckTaskButtonClicked()" << std::endl;

    item->setTaskAsCompleted(index);

    std::cout << "ItemController::onCheckTaskButtonClicked() - item->tasks[index].isCompleted() = " << item->tasks[index].isCompleted() << std::endl;

    showTask(item->getVector());
}
//
////search
//
//void ItemController::onCheckSearchButtonClicked(int index) {
//
//    std::cout << "ItemController::onCheckSearchButtonClicked()" << std::endl;
//
//    item->setTaskAsCompleted(index);
//
//    std::cout << "ItemController::onCheckSearchButtonClicked() - item->tasks[index].isCompleted() = " << item->tasks[index].isCompleted() << std::endl;
//
////    searchItem(frame->getSearchKeyword());
//}