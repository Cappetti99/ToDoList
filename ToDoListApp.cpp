//
// Created by cappe on 03/10/23.
//

#include "ToDoListApp.h"


bool ToDoListApp::OnInit() {
    // Create the main application frame
    frame = new wxFrame(nullptr, wxID_ANY, "To-Do List App", wxDefaultPosition, wxSize(600, 400));

    // Create a button to open the CustomWindow
    wxButton* openButton = new wxButton(frame, wxID_ANY, "Open Second Window", wxDefaultPosition, wxDefaultSize);

    // Bind an event handler for the button click event
    openButton->Bind(wxEVT_BUTTON, &ToDoListApp::OnOpenButtonClick, this);

    frame->Show(true);

    return true;
}

void ToDoListApp::OnOpenButtonClick(wxCommandEvent& event) {
    // Create and show the CustomWindow
    CustomWindow* taskListView = new CustomWindow(frame, "Tasks in Sample List", wxDefaultPosition, wxSize(400, 300));
    taskListView->Show(true);
}


wxIMPLEMENT_APP(ToDoListApp);


