//
// Created by cappe on 14/12/23.
//

#include "Frame.h"


wxBEGIN_EVENT_TABLE(Frame, wxFrame)
                EVT_BUTTON(ID_AddTaskButton, Frame::addTaskButton)
                EVT_BUTTON(ID_RemoveTaskButton, Frame::removeTaskButton)
                EVT_BUTTON(ID_SearchTaskButton, Frame::searchTaskButton)
                EVT_CHECKLISTBOX(ID_Check, Frame::checkTaskButton)
                EVT_BUTTON(ID_RemoveSearch, Frame::removeSearchButton)
                EVT_TEXT(ID_TextCtrl,Frame::onTextChange)
                EVT_TEXT_ENTER(ID_TextCtrl,Frame::addTaskButton)
                EVT_TEXT(ID_SearchText,Frame::onSearchTextChange)
                EVT_TEXT_ENTER(ID_SearchText,Frame::searchTaskButton)

wxEND_EVENT_TABLE()


Frame::Frame(const wxString &title, const wxPoint &pos, const wxSize &size, ItemControllerObserver *observer)
        : wxFrame(NULL, wxID_ANY, title, pos, size), observer(observer) {

    std::cout << "Frame created" << std::endl;
    frame = this;

    auto buttonsSizer = new wxBoxSizer(wxHORIZONTAL);

    taskTextCtrl = new wxTextCtrl(this, ID_TextCtrl, "Enter New Task Name", wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
    taskTextCtrl->SetDefaultStyle(wxTextAttr(*wxLIGHT_GREY));


    taskListBox = new wxCheckListBox(this, ID_Check, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxLB_SINGLE);


    //bottoni
    auto addButton = new wxButton(this, ID_AddTaskButton, "Add Task");
    auto removeButton = new wxButton(this, ID_RemoveTaskButton, "Remove Task");
    auto searchButton = new wxButton(this, ID_SearchTaskButton, "Search Tasks");

    searchInput = new wxTextCtrl(this, ID_SearchText, "Enter Task name", wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
    searchInput->SetDefaultStyle(wxTextAttr(*wxLIGHT_GREY));

    buttonsSizer->Add(addButton, 5, wxALL, 10);
    buttonsSizer->Add(removeButton, 5, wxALL, 10);
    buttonsSizer->Add(searchButton, 5, wxALL, 10);
    buttonsSizer->Add(searchInput, 5, wxALL, 10);

    auto mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(buttonsSizer, 0, wxALIGN_CENTER | wxTOP, 20);
    mainSizer->Add(taskTextCtrl, 0, wxALL | wxEXPAND, 5);
    mainSizer->Add(taskListBox, 1, wxEXPAND | wxALL, 10);

    SetSizerAndFit(mainSizer);

    SetSize(wxSize(800, 600));
}

void Frame::onTextClick(wxCommandEvent &event) {
    taskTextCtrl->SetInsertionPointEnd();
}

void Frame::onTextChange(wxCommandEvent &event){
    if (taskTextCtrl->GetLineLength(0)>=1) {
        wxString b = taskTextCtrl->GetValue();
        long pos = taskTextCtrl->GetInsertionPoint();

        wxString a = taskTextCtrl->GetRange(pos - 1, pos);
        b = b.Remove(pos - 1, 1);
        if (b.IsSameAs("Enter New Task Name", true)) {
            taskTextCtrl->ChangeValue(a);
            taskTextCtrl->SetDefaultStyle(wxTextAttr(*wxBLACK));
            taskTextCtrl->SetInsertionPointEnd();
        }
    }
}


void Frame::onSearchTextChange(wxCommandEvent &event){
    if(searchInput->GetLineLength(0)>=1){
        wxString b=searchInput->GetValue();
        long pos=searchInput->GetInsertionPoint();
        wxString a= searchInput->GetRange(pos - 1,pos);
        b = b.Remove(pos - 1,1);
        if(b.IsSameAs("Enter Task name", true)){
            searchInput->ChangeValue(a);
            searchInput->SetDefaultStyle(wxTextAttr(*wxBLACK));
            searchInput->SetInsertionPointEnd();
        }
    }
}

void Frame::addTaskButton(wxCommandEvent &event) { //fixme c'è da sistemare delle casistiche

    //controllo che non sia vuoto
    if (taskTextCtrl->IsEmpty()) {
        wxMessageBox("Inserisci un task!");
        return;
    }

    wxString name = taskTextCtrl->GetValue();
    if(name.IsSameAs("Enter New Task Name", true)){
        wxMessageBox("Inserisci un task!");
        return;
    }
    else{
    DateSelection dateSelection(this, "Select expiration date:");
    if (!name.IsEmpty()) {
        if (dateSelection.ShowModal() == wxID_OK) {
            wxDateTime dateTime = dateSelection.getDatePicker()->GetValue();
            //fai un controllo in modo che non abbia una data passata
            if (dateTime.IsEarlierThan(wxDateTime::Now() - wxTimeSpan::Days(1))) {
                //tolgo un giorno perche' sennò da problemi con oggi
                wxMessageBox("Hai inserito una data passata!");
                return;
            } //gestire il cancel

            PrioritySelection prioritySelection(this, "Select priority:");
            if (prioritySelection.ShowModal() == wxID_OK) {
                Priority priority = prioritySelection.getSelectedPriority();
                if (priority != Priority::Low and priority != Priority::Medium and priority != Priority::High) {
                    wxMessageBox("Inserisci una priorità!");
                    return;
                }

                Nome = name;
                Data = dateTime;
                Priorità = priority;

                taskTextCtrl->Clear();

                if (observer) {
                    observer->onAddTaskButtonClicked();
                }

            }
        }
    }
    }
}


void Frame::removeTaskButton(wxCommandEvent &event) {

    int selectedIndex = taskListBox->GetSelection();
    if (selectedIndex != wxNOT_FOUND) {
        wxMessageDialog confirmDialog(this,
                                      "Sei sicuro di volerla eliminare?", "Conferma eliminazione",
                                      wxYES_NO | wxICON_QUESTION);

        int response = confirmDialog.ShowModal();

        if (response == wxID_YES) {
            if (observer) {
                observer->onRemoveTaskButtonClicked(selectedIndex);
            }
        }
    }
}

void Frame::searchTaskButton(wxCommandEvent &event) {

    wxString searchKeyword = searchInput->GetValue();

    namesSearch.clear();
    datesSearch.clear();
    prioritiesSearch.clear();
    //li pulisco per visualizzarli tutti nuovi quando si fa una nuova ricerca

    if (observer) {
        observer->onSearchTaskButtonClicked(searchKeyword);
    }

}

void Frame::showTaskFrame(wxString name, wxDateTime date, Priority priority, bool completed, int index) {

    wxString priorityString;

    if (priority == Priority::High) {
        priorityString = "HIGH";
    } else if (priority == Priority::Medium) {
        priorityString = "MEDIUM";
    } else if (priority == Priority::Low) {
        priorityString = "LOW";
    }

    wxString taskString = name + " - Priority: " + priorityString +
                          " - " + date.Format("%d %B, %Y");

    taskListBox->Append(taskString);

    if (completed == true) {
        taskListBox->Check(index, true);

    }
    taskTextCtrl->ChangeValue("Enter New Task Name");
}


void Frame::ClearFrame() {
    taskListBox->Clear();
}

void Frame::showSearchFrame(std::vector<wxString> namesSearch, std::vector<wxDateTime> datesSearch,
                            std::vector<Priority> prioritiesSearch, std::vector<bool> completedSearch,
                            std::vector<wxString> allNames, std::vector<wxDateTime> allDates,
                            std::vector<Priority> allPriorities, std::vector<bool> allCompleted) {

    this->namesSearch = namesSearch;
    this->datesSearch = datesSearch;
    this->prioritiesSearch = prioritiesSearch;
    this->completedSearch = completedSearch;

    this->names = allNames;
    this->dates = allDates;
    this->priorities = allPriorities;
    this->completed = allCompleted;

//creo una nuova finestra per visualizzare i risultati della ricerca

    searchResultFrame = new wxFrame(frame, wxID_ANY, "Risultati della ricerca", wxDefaultPosition, wxDefaultSize);

    searchResultFrame->Bind(wxEVT_CLOSE_WINDOW, &Frame::CloseRefresh, this);
    auto searchResultSizer = new wxBoxSizer(wxVERTICAL);
    searchResultFrame->SetSizer(searchResultSizer);

    searchBox = new wxCheckListBox(searchResultFrame, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, nullptr,
                                   wxLB_SINGLE);

    searchResultSizer->Add(searchBox, 1, wxEXPAND | wxALL, 10);

    auto removeSearchButton = new wxButton(searchResultFrame, ID_RemoveSearch, "Remove Task");
    removeSearchButton->Bind(wxEVT_BUTTON, &Frame::removeSearchButton, this);
    auto buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    searchResultSizer->Add(removeSearchButton, 0, wxALL, 5);
    searchResultSizer->Add(buttonSizer, 0, wxALIGN_RIGHT);

    searchShow(namesSearch, datesSearch, prioritiesSearch, completedSearch);

    searchResultFrame->Show();

}

void Frame::searchShow(std::vector<wxString> namesSearch, std::vector<wxDateTime> datesSearch,
                       std::vector<Priority> prioritiesSearch, std::vector<bool> completedSearch) {

    this->namesSearch = namesSearch;
    this->datesSearch = datesSearch;
    this->prioritiesSearch = prioritiesSearch;
    this->completedSearch = completedSearch;

searchBox->Clear();
    for (int j = 0; j < namesSearch.size(); j++) {
        wxString priorityString;

        if (prioritiesSearch[j] == Priority::High) {
            priorityString = "HIGH";
        } else if (prioritiesSearch[j] == Priority::Medium) {
            priorityString = "MEDIUM";
        } else if (prioritiesSearch[j] == Priority::Low) {
            priorityString = "LOW";
        }

        wxString taskString = namesSearch[j] + " - Priority: " + priorityString +
                              " - " + datesSearch[j].Format("%d %B, %Y");

        searchBox->Append(taskString);

        if (completedSearch[j] == true) {
            searchBox->Check(j, true);
        }
    }
}


void Frame::CloseRefresh(wxCloseEvent &event) {
    for (int i = 0; i < namesSearch.size(); i++) {
        if (searchBox->IsChecked(i) == true) {
            completedSearch[i] = true;
        } else if (searchBox->IsChecked(i) == false) {
            completedSearch[i] = false;
        }
    }

    for (int i = 0; i < namesSearch.size(); i++) {
        for (int j = 0; j < names.size(); j++) {
            if (namesSearch[i] == names[j]) {
                if (completedSearch[i] !=
                    completed[j]) { //quando faccio il check non cambio il valore di completedSearch
                    if (completedSearch[i] == true) {
                        completed[j] = true;
                    } else if (completedSearch[i] == false) {
                        completed[j] = false;
                    }
                    if (observer) {
                        observer->onCheckTaskButtonClicked(j); //lo si fa troppe volte
                    }
                }
            }
        }
    }

    event.Skip();
}

const wxString &Frame::getNome() const {
    return Nome;
}

const wxDateTime &Frame::getData() const {
    return Data;
}

Priority Frame::getPriorità() const {
    return Priorità;
}


void Frame::checkTaskButton(wxCommandEvent &event) {


    int selectedIndex = event.GetSelection();

    if (taskListBox->IsChecked(selectedIndex)) {

        if (observer) {
            observer->onCheckTaskButtonClicked(selectedIndex);
        }

    } else if (!taskListBox->IsChecked(selectedIndex)) {

        if (observer) {
            observer->onCheckTaskButtonClicked(selectedIndex);
        }
    }

}

void Frame::removeSearchButton(wxCommandEvent &event) {

    int selectedIndex = searchBox->GetSelection();
    int c = 0;
    while (namesSearch[selectedIndex] != names[c] ){
        c++;
    }
    if (namesSearch[selectedIndex] == names[c] ) {
        if (selectedIndex != wxNOT_FOUND) {
            wxMessageDialog confirmDialog(searchResultFrame,
                                          "Sei sicuro di volerla eliminare?", "Conferma eliminazione",
                                          wxYES_NO | wxICON_QUESTION);

            int response = confirmDialog.ShowModal();

            if (response == wxID_YES) {
                namesSearch.erase(namesSearch.begin() + selectedIndex);
                datesSearch.erase(datesSearch.begin() + selectedIndex);
                prioritiesSearch.erase(prioritiesSearch.begin() + selectedIndex);
                completedSearch.erase(completedSearch.begin() + selectedIndex); //tolgo dalle liste di ricerca
                searchBox->Delete(selectedIndex); //tolgo dalla lista di ricerca
                searchShow(namesSearch, datesSearch, prioritiesSearch, completedSearch); //aggiorno la lista di ricerca
                if (observer) {
                    observer->onRemoveTaskButtonClicked(c);
                }
            }
        }

    }
    c=0;
}
