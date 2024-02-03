//#include <iostream>
//#include <wx/wx.h>
//
//#include "ToDoApp.h"
//
//int main(int argc, char *argv[]) {
//
//    Model *model = new Model;
//    Control *control = new Control(model);
//    View *view = new View(model, control);
//
//    ToDoApp myApp; // Crea un'istanza della tua classe applicazione
//    wxApp::SetInstance(&myApp); // Imposta l'istanza globale
//
//    wxEntryStart(argc, argv); // Inizia il punto di ingresso di wxWidgets
//
//    if (!wxTheApp->OnInit()) {
//        wxEntryCleanup(); // Pulisci le risorse di wxWidgets
//        return 1; // Errore durante l'inizializzazione dell'applicazione
//    }
//    wxTheApp->OnInit()
//
//    return wxTheApp->OnRun(); // Esegui il ciclo principale dell'applicazione
//}
//
