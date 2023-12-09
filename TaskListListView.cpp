//
// Created by cappe on 22/09/23.
//

#include "TaskListListView.h"
//#include "Task.h"

/*
wxBEGIN_EVENT_TABLE(TaskListListView, wxFrame)
        EVT_BUTTON(ID_AddList ,TaskListListController::OnAddListButtonClick);
        EVT_BUTTON(ID_RenameList ,TaskListListController::OnEditListButtonClick);
        EVT_BUTTON(ID_RemoveList,TaskListListController::OnRemoveListButtonClick);
        EVT_BUTTON(ID_SearchList, TaskListListController::OnSearchListButtonClick);
wxEND_EVENT_TABLE()
*/
    TaskListListView::TaskListListView(wxWindow* parent, const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(parent, wxID_ANY, title, wxDefaultPosition, wxDefaultSize){

    auto mainSizer = new wxBoxSizer(wxVERTICAL);

    taskTextCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize,
                                       wxTE_PROCESS_ENTER);
    //mainSizer->Add(taskTextCtrl, 0, wxEXPAND | wxALL, 5);

     addListButton = new wxButton(this, ID_AddList, "Add List");
     removeListButton = new wxButton(this, ID_RemoveList, "Remove List");
     searchListButton = new wxButton(this, ID_SearchList, "Search List");
     renameListButton = new wxButton(this, ID_RenameList, "Rename List");

    //addListButton->Bind(wxEVT_BUTTON, &TaskListListView::OnAddListButtonClick, this, ID_AddList);

    auto buttonsSizer = new wxBoxSizer(wxHORIZONTAL);

    buttonsSizer->Add(addListButton, 5, wxALL, 10);
    buttonsSizer->Add(removeListButton, 5, wxALL, 10);
    buttonsSizer->Add(searchListButton, 5, wxALL, 10);
    buttonsSizer->Add(renameListButton, 5, wxALL, 10);

    mainSizer->Add(buttonsSizer, 0, wxALIGN_LEFT);
    mainSizer->Add(taskTextCtrl, 0, wxALL | wxEXPAND, 5);


    auto listBoxSizer = new wxBoxSizer(wxVERTICAL);

    taskListList = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxLB_SINGLE);
    listBoxSizer->Add(taskListList, 1, wxEXPAND | wxALL, 10);

    mainSizer->Add(listBoxSizer, 1, wxEXPAND | wxALL, 5);

    this->SetSizer(mainSizer);

}

wxTextCtrl *TaskListListView::getTaskTextCtrl() const {
    return taskTextCtrl;
}

void TaskListListView::setTaskTextCtrl(wxTextCtrl *taskTextCtrl) {
    TaskListListView::taskTextCtrl = taskTextCtrl;
}


wxString & TaskListListView::OnAddListButtonClick() {


    wxString name = wxGetTextFromUser("Enter title of the list:"); //serve per mettere il nome direttamente da qui

    return name;

}

void TaskListListView::RefreshTaskList(std::vector<TaskList> *vector){

    this->lists=*vector;

    //riordina in ordine alfabetico
    for (const auto& task: lists){
        wxString taskString = task.getName();
        taskListList->Append(taskString);
    }
}



wxButton *TaskListListView::getAddListButton() const {
    return addListButton;
}

const wxString &TaskListListView::getTitle() const {
    return title;
}

void TaskListListView::setTitle(const wxString &title) {
    TaskListListView::title = title;
}





