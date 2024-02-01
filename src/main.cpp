#include <iostream>
#include <wx/wx.h>

#include "ToDoApp.h"




int main(int argc, char *argv[]) {

    Model *model = new Model;
    Control *control = new Control(/*model*/);
    View *view = new View(model, control); //todo da mettere

    ToDoApp myApp; // Create an instance of your application class
    wxApp::SetInstance(&myApp); // Set it as the global instance

    wxEntryStart(argc, argv); // Start the wxWidgets entry point

    wxTheApp->OnInit();// Initialize the application

    myApp.OnInit(model, control); //todo da mettere


    if (!wxTheApp->OnRun()) {
        return 0; // Run the application
    }

    wxTheApp->OnRun(); // Run the application's main event loop

    wxEntryCleanup(); // Clean up wxWidgets resources

    return 0;
}
