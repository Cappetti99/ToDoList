//
// Created by cappe on 18/12/23.
//

#include "ItemController.h"

ItemController::ItemController(TaskList *m) {
    this->model = m;
}

ItemController::~ItemController() = default;

void ItemController::addTask(wxString name, wxDateTime date, Priority priority) {
    bool completed = false;
    model->addTask(name, date, priority, completed);
}

void ItemController::removeTask(int index) {

    model->removeTask(index);
}

void ItemController::searchTask() {
    std::cout << "searchTask" << std::endl;
}

void ItemController::markAsCompleted(int index) {

    model->setTaskAsCompleted(index);
}

void ItemController::editTask(int index, wxString name, wxDateTime date, Priority priority) {

    model->editTask(index, name, date, priority);
}


//void ItemController::addItem(wxString name, wxDateTime date, Priority priority) {

//va ripensato il sort
//    item->addTask(name, date, priority);
//    std::vector<Task> temp =item->getVector();
//    std::sort(temp.begin(), temp.end(),
//              [](const Task &a, const Task &b) {
//                  return a.getExpirationDate() < b.getExpirationDate();
//              });
//    std::sort(temp.begin(), temp.end(),
//              [](const Task &a, const Task &b) {
//                  return a.getPriority() > b.getPriority();
//              });
//    item->tasks=temp;
//    showTask(temp);

//    model->addTask(name, date, priority);

//}

//void ItemController::onAddTaskButtonClicked() {
//
//    addItem(frame->getNome(), frame->getData(), frame->getPriorità());
//}
//
//
//void ItemController::showTask(std::vector<Task> vettore) {
//    frame->ClearFrame();
//    for (int i = 0; i < vettore.size(); i++) {
//
//        frame->showTaskFrame(item->getName(i), item->getDate(i), item->getPriority(i), item->getCompleted(i), i);
//    }
//
//}
//
//void ItemController::onRemoveTaskButtonClicked(int index) {
//
//    removeItem(index);
//
//}
//
//void ItemController::removeItem(int index) {
//
//    //wxString name = item->getName(index);
//    item->removeTask(index);
//    showTask(item->getVector());
//
//    //removeFrame(index);
//}
//
//
//void ItemController::onSearchTaskButtonClicked(wxString searchKeyword) {
//
//    searchItem(searchKeyword);
//
//}
//
//void ItemController::markItemAsCompleted() {
//
//}
//
//void ItemController::searchItem(wxString searchKeyword) {
//
//    std::vector<Task *> tasks;
//    std::vector<wxString> namesSearch;
//    std::vector<wxDateTime> datesSearch;
//    std::vector<Priority> prioritiesSearch;
//    std::vector<bool> compleatedSearch;
//
//    std::vector<wxString> allNames;
//    std::vector<wxDateTime> allDates;
//    std::vector<Priority> allPriorities;
//    std::vector<bool> allCompleated;
//
//    for (int i = 0; i < item->getVector().size(); i++) {
//        allNames.push_back(item->getName(i));
//        allDates.push_back(item->getDate(i));
//        allPriorities.push_back(item->getPriority(i));
//        allCompleated.push_back(item->getCompleted(i));
//        wxString taskName = item->getName(i);
//        if (taskName.Find(searchKeyword) != wxNOT_FOUND) {
//            tasks.push_back(&item->tasks[i]);
//            namesSearch.push_back(item->getName(i));
//            datesSearch.push_back(item->getDate(i));
//            prioritiesSearch.push_back(item->getPriority(i));
//            compleatedSearch.push_back(item->getCompleted(i));
//        }
//    }
//    if (tasks.size() > 0) {
//        frame->showSearchFrame(namesSearch, datesSearch, prioritiesSearch, compleatedSearch, allNames, allDates,
//                               allPriorities, allCompleated);
//    }
//
//}
//
//void ItemController::onCheckTaskButtonClicked(int index) {
//
//    item->setTaskAsCompleted(index);
//
//    showTask(item->getVector());
//}
