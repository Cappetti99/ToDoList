//
// Created by cappe on 27/09/23.
//

#include "CustomWindow.h"


CustomWindow::CustomWindow(wxWindow* parent, const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(parent, wxID_ANY, title, pos, size) {

    Windows1();

}

void CustomWindow::Windows1() {

    mainSizer = new wxBoxSizer(wxVERTICAL);
    //wxStaticText* label = new wxStaticText(this, wxID_ANY, "This is a custom window."); //va cambiata questa
    //mainSizer->Add(label, 0, wxALIGN_CENTER | wxALL, 10);

    auto* taskListListView = new TaskListListView(this, "Tasks in Sample List", taskLists);
    mainSizer->Add(taskListListView, 0, wxALIGN_CENTER | wxALL, 10);
    SetSizerAndFit(mainSizer);
    taskListListView->Show(true);




    //todo implementare tutta la prima finestra e una condizione per andare sulla seconda

}

void CustomWindow::Windows2() {
    mainSizer = new wxBoxSizer(wxVERTICAL);
    SetSizerAndFit(mainSizer);
    taskListListView->Show();


//todo implementare tutta la seconda finestra
}

