#include <iostream>
#include <wx/wx.h>
#include "ToDoApp.h"


int main(int argc, char *argv[]) {
    ToDoApp myApp; // Create an instance of your application class
    wxApp::SetInstance(&myApp); // Set it as the global instance

    wxEntryStart(argc, argv); // Start the wxWidgets entry point

    wxTheApp->OnInit();// Initialize the application

    if (!wxTheApp->OnRun()) {
        return 0; // Run the application
    }

    wxTheApp->OnRun(); // Run the application's main event loop

    wxEntryCleanup(); // Clean up wxWidgets resources

    return 0;
}
