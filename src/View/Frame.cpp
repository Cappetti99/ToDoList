//
// Created by cappe on 14/12/23.
//

#include "Frame.h"

#define RED_TEXT "\033[1;31m"
#define GREEN_TEXT "\033[1;32m"
#define YELLOW_TEXT "\033[1;33m"
#define RESET_TEXT "\033[0m"


wxBEGIN_EVENT_TABLE(Frame, wxFrame)
                EVT_BUTTON(ID_AddTaskButton, Frame::addTaskButton)
                EVT_BUTTON(ID_RemoveTaskButton, Frame::removeTaskButton)
                EVT_BUTTON(ID_SearchTaskButton, Frame::searchTaskButton)
                EVT_CHECKLISTBOX(ID_Check, Frame::checkTaskButton)
//                EVT_CHECKLISTBOX(ID_SearchTaskButton, Frame::checkSearch)
wxEND_EVENT_TABLE()


Frame::Frame(const wxString &title, const wxPoint &pos, const wxSize &size, ItemControllerObserver *observer)
        : wxFrame(NULL, wxID_ANY, title, pos, size), observer(observer) {

    std::cout << "Frame created" << std::endl;
    frame = this;

    auto buttonsSizer = new wxBoxSizer(wxHORIZONTAL);

    taskTextCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);

    taskListBox = new wxCheckListBox(this, ID_Check, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxLB_SINGLE);


    //bottoni
    auto addButton = new wxButton(this, ID_AddTaskButton, "Add Task");
    auto removeButton = new wxButton(this, ID_RemoveTaskButton, "Remove Task");
    auto searchButton = new wxButton(this, ID_SearchTaskButton, "Search Tasks");

    searchInput = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);

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

void Frame::addTaskButton(wxCommandEvent &event) { //fixme c'è da sistemare delle casistiche
//    std::cout << "addTaskButton" << std::endl;
    //controllo che non sia vuoto
    if (taskTextCtrl->IsEmpty()) {
        wxMessageBox("Inserisci un task!");
        return;
    }

    wxString name = taskTextCtrl->GetValue();
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


void Frame::removeTaskButton(wxCommandEvent &event) {

    std::cout << "removeTaskButton" << std::endl;

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

//    std::cout << "searchTaskButton" << std::endl;

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
    std::cout << "8" << std::endl;

}


void Frame::ClearFrame() {
    std::cout << "Frame::ClearFrame()" << std::endl;
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

    //i vettori hanno i valori giusti

//creo una nuova finestra per visualizzare i risultati della ricerca

    auto searchResultFrame = new wxFrame(frame, wxID_ANY, "Risultati della ricerca", wxDefaultPosition, wxDefaultSize);

    searchResultFrame->Bind(wxEVT_CLOSE_WINDOW, &Frame::CloseRefresh, this);
    auto searchResultSizer = new wxBoxSizer(wxVERTICAL);
    searchResultFrame->SetSizer(searchResultSizer);

    searchBox = new wxCheckListBox(searchResultFrame, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, nullptr,
                                   wxLB_SINGLE);

    searchResultSizer->Add(searchBox, 1, wxEXPAND | wxALL, 10);

    auto removeButton = new wxButton(searchResultFrame, ID_RemoveTaskButton, "Remove Task");
    auto buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    searchResultSizer->Add(removeButton, 0, wxALL, 5);
    searchResultSizer->Add(buttonSizer, 0, wxALIGN_RIGHT);

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


    //searchBox->Bind(wxEVT_CHECKLISTBOX, &Frame::checkTaskButton, this);

    searchResultFrame->Show();

}


void Frame::CloseRefresh(wxCloseEvent &event) {
//    ClearFrame();
    for (int i = 0; i < namesSearch.size(); i++) {
        if (searchBox->IsChecked(i) == true) {
            completedSearch[i] = true;
        } else if(searchBox->IsChecked(i) == false) {
            completedSearch[i] = false;
        }
    }

    for (int i = 0; i < namesSearch.size(); i++) {
        std::cout << "1" << std::endl;
        for (int j = 0; j < names.size(); j++) {
            std::cout << "2" << std::endl;
            if (namesSearch[i] == names[j]) {
                std::cout << "3" << std::endl;
                if (completedSearch[i] != completed[j]) { //quando faccio il check non cambio il valore di completedSearch
                    std::cout << "4" << std::endl;
                    if (completedSearch[i] == true) {
                        std::cout << "5" << std::endl;
                        completed[j] = true;
                        std::cout << "6" << std::endl;
                    } else if (completedSearch[i] == false) {
                        std::cout << "7" << std::endl;
                        completed[j] = false;
                        std::cout << "8" << std::endl;
                    }
                    if (observer) {
                        std::cout << "entro nell'observer" << std::endl;
                        observer->onCheckTaskButtonClicked(j); //lo si fa troppe volte
                        std::cout << "ho fatto l'observer" << std::endl;
                    }
                }
            }
        }
    }

//    for (int i = 0; i < names.size(); i++) {
//        showTaskFrame(names[i], dates[i], priorities[i], completed[i], i);
//
//        taskListBox->Check(i, completed[i]);
//    }

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

    std::cout << "checkTaskButton1" << std::endl;

    int selectedIndex = event.GetSelection();

    if (taskListBox->IsChecked(selectedIndex)) {
        std::cout << "checkTaskButton2" << std::endl;

        if (observer) {
            observer->onCheckTaskButtonClicked(selectedIndex);
        }

    } else if (!taskListBox->IsChecked(selectedIndex)) {
        std::cout << "checkTaskButton3" << std::endl;

        if (observer) {
            observer->onCheckTaskButtonClicked(selectedIndex);
        }
    }
    //entro comunque nell'observer in entrambi i casi?

}

//void Frame::checkSearch(wxCommandEvent &event) {
//
//    std::cout << "checkSearch1" << std::endl;
//
//    int selectedIndex = event.GetSelection();
//
//    if (searchBox->IsChecked(selectedIndex)) {
//        std::cout << "checkSearch2" << std::endl;
//
//        if (observer) {
//            observer->onCheckSearchButtonClicked(selectedIndex);
//        }
//
//    } else if (!searchBox->IsChecked(selectedIndex)) {
//        std::cout << "checkSearch3" << std::endl;
//
//        if (observer) {
//            observer->onCheckSearchButtonClicked(selectedIndex);
//        }
//    }
//    //entro comunque nell'observer in entrambi i casi?
//
//}