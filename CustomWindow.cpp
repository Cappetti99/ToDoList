//
// Created by cappe on 27/09/23.
//

#include "CustomWindow.h"


CustomWindow::CustomWindow(wxWindow* parent, const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(parent, wxID_ANY, title, pos, size) {

    mainSizer = new wxBoxSizer(wxVERTICAL);
    wxStaticText* label = new wxStaticText(this, wxID_ANY, "This is a custom window.");
    mainSizer->Add(label, 0, wxALIGN_CENTER | wxALL, 10);

    SetSizerAndFit(mainSizer);
}