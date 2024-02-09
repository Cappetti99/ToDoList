//
// Created by cappe on 14/12/23.
//

#include "Frame.h"


wxBEGIN_EVENT_TABLE(Frame, wxFrame)
            //normali funzioni
                EVT_BUTTON(ID_AddTaskButton, Frame::addTaskButton)
                EVT_BUTTON(ID_RemoveTaskButton, Frame::removeTaskButton)
                EVT_CHECKLISTBOX(ID_Check, Frame::checkTaskButton)
                EVT_BUTTON(ID_EditTaskButton, Frame::editTaskButton)
            //funzioni del search
                EVT_BUTTON(ID_SearchTaskButton, Frame::searchTaskButton)
                EVT_BUTTON(ID_RemoveSearch, Frame::removeOfSearch)
                EVT_BUTTON(ID_EditSearch, Frame::editOfSearch)
                EVT_CHECKLISTBOX(ID_CheckSearch, Frame::checkSearch)
            //comandi da tastiera
                EVT_TEXT(ID_TextCtrl, Frame::onTextChange)
                EVT_TEXT_ENTER(ID_TextCtrl, Frame::addTaskButton)
                EVT_TEXT(ID_SearchText, Frame::onSearchTextChange)
                EVT_TEXT_ENTER(ID_SearchText, Frame::searchTaskButton)

                //menù
                EVT_MENU(ID_SBPriority, Frame::sortByPriority)
                EVT_MENU(ID_SBDate, Frame::sortByDate)
                EVT_MENU(ID_SBAlphabet, Frame::sortByAlphabet)

wxEND_EVENT_TABLE()


Frame::Frame(TaskList *taskList, ItemController *itemController, const wxString &title, const wxPoint &pos,
             const wxSize &size)
        : wxFrame(nullptr, wxID_ANY, title, pos, size) {

    this->taskList = taskList;
    this->itemController = itemController;
    taskList->addObserver(this);
    frame = this;

    auto buttonsSizer = new wxBoxSizer(wxHORIZONTAL);
    taskTextCtrl = new wxTextCtrl(this, ID_TextCtrl, "Enter New Task Name", wxDefaultPosition, wxDefaultSize,
                                  wxTE_PROCESS_ENTER);
    taskTextCtrl->SetDefaultStyle(wxTextAttr(*wxLIGHT_GREY));
    taskListBox = new wxCheckListBox(this, ID_Check, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxLB_SINGLE);
    taskListBox->Bind(wxEVT_LEFT_DCLICK, &Frame::editMouse, this);

    wxMenuBar* menuBar = new wxMenuBar;

    //bottoni
    auto addButton = new wxButton(this, ID_AddTaskButton, "Add Task");
    auto removeButton = new wxButton(this, ID_RemoveTaskButton, "Remove Task");
    auto searchButton = new wxButton(this, ID_SearchTaskButton, "Search Tasks");
    auto editButton = new wxButton(this, ID_EditTaskButton, "Edit Task");

    wxMenu* fileMenu = new wxMenu;

    fileMenu->Append(ID_SBPriority, "&Sort by Priority", "Piorità");
    fileMenu->Append(ID_SBDate, "&Sort by Date", "Data");
    fileMenu->Append(ID_SBAlphabet, "&Sort by alphabetical order", "Alfabetico");

    menuBar->Append(fileMenu, "&Sort");

    SetMenuBar(menuBar);


    searchInput = new wxTextCtrl(this, ID_SearchText, "Task Name", wxDefaultPosition, wxDefaultSize,
                                 wxTE_PROCESS_ENTER);
    searchInput->SetDefaultStyle(wxTextAttr(*wxLIGHT_GREY));

    buttonsSizer->Add(addButton, 5, wxALL, 10);
    buttonsSizer->Add(removeButton, 5, wxALL, 10);
    buttonsSizer->Add(editButton, 5, wxALL, 10);
    buttonsSizer->Add(searchButton, 5, wxALL, 10);
    buttonsSizer->Add(searchInput, 5, wxALL, 10);


    auto mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(buttonsSizer, 0, wxALIGN_CENTER | wxTOP, 20);
    mainSizer->Add(taskTextCtrl, 0, wxALL | wxEXPAND, 5);
    mainSizer->Add(taskListBox, 1, wxEXPAND | wxALL, 10);

    SetSizerAndFit(mainSizer);

    SetSize(wxSize(800, 600));
}


Frame::~Frame() {
    taskList->removeObserver(this);
}

void Frame::editMouse(wxMouseEvent &event) {
    std::cout << "editMouse" << std::endl;
    int selectedIndex = taskListBox->GetSelection();
    std::cout << selectedIndex << std::endl;
    if (selectedIndex != wxNOT_FOUND) {
        TaskEditDialog editDialog(this, "Edit: ", taskList->getVector()[selectedIndex].getTitle(),
                                  taskList->getVector()[selectedIndex].getExpirationDate(),
                                  taskList->getVector()[selectedIndex].getPriority());

        if (editDialog.ShowModal() == wxID_OK) {
            wxString taskName = editDialog.getTaskTitle();
            wxDateTime dateTime = editDialog.getExpirationDate();
            Priority newPriority = editDialog.getPriority();

            if (taskName.IsEmpty()) {
                wxMessageBox("Inserisci un task!");
                return;
            } else if (dateTime.IsEarlierThan(wxDateTime::Now() - wxTimeSpan::Days(1))) {
                wxMessageBox("Hai inserito una data passata!");
                return;
            } else if (newPriority != Priority::Low and newPriority != Priority::Medium and
                       newPriority != Priority::High) {
                wxMessageBox("Inserisci una priorità!");
                return;
            }

            itemController->editTask(selectedIndex, taskName, dateTime, newPriority);

        }
    }
}


void Frame::show() {
    Show(true);
}

void Frame::update() {

    taskListBox->Clear();
    std::cout << "update" << std::endl;
    std::vector<Task> tasks = taskList->getVector();

    for (int i = 0; i < tasks.size(); i++) {
        wxString priorityString;

        if (tasks[i].getPriority() == Priority::High) {
            priorityString = "HIGH";
        } else if (tasks[i].getPriority() == Priority::Medium) {
            priorityString = "MEDIUM";
        } else if (tasks[i].getPriority() == Priority::Low) {
            priorityString = "LOW";
        }

        wxString taskString = tasks[i].getTitle() + " - Priority: " + priorityString +
                              " - " + tasks[i].getExpirationDate().Format("%d %B, %Y");

        taskListBox->Append(taskString);

        if (tasks[i].isCompleted()) {
            taskListBox->Check(i, true);
        }
    }
}

void Frame::addTaskButton(wxCommandEvent &event) {

    //controllo che non sia vuoto
    if (taskTextCtrl->IsEmpty()) {
        wxMessageBox("Inserisci un task!");
        return;
    }

    wxString name = taskTextCtrl->GetValue();

    if (name.IsSameAs("Enter New Task Name", true)) {
        wxMessageBox("Inserisci un task!");
        return;
    } else {
        DateSelectionDialog dateSelection(this, "Select expiration date:");
        if (!name.IsEmpty()) {
            if (dateSelection.ShowModal() == wxID_OK) {
                wxDateTime dateTime = dateSelection.getDatePicker()->GetValue();
                //controllo in modo che non abbia una data passata
                if (dateTime.IsEarlierThan(wxDateTime::Now() - wxTimeSpan::Days(1))) {
                    //tolgo un giorno perche' sennò da problemi con oggi
                    wxMessageBox("Hai inserito una data passata!");
                    return;
                }

                PrioritySelectionDialog prioritySelection(this, "Select priority:");
                if (prioritySelection.ShowModal() == wxID_OK) {
                    Priority priority = prioritySelection.getSelectedPriority();
                    if (priority != Priority::Low and priority != Priority::Medium and priority != Priority::High) {
                        wxMessageBox("Inserisci una priorità!");
                        return;
                    }

                    taskTextCtrl->Clear();

                    itemController->addTask(name, dateTime, priority);

                }
            }
        }
    }
}

void Frame::checkTaskButton(wxCommandEvent &event) {

    int selectedIndex = event.GetSelection();

    if (taskListBox->IsChecked(selectedIndex)) {

        itemController->markAsCompleted(selectedIndex);

    } else if (!taskListBox->IsChecked(selectedIndex)) {

        itemController->markAsCompleted(selectedIndex);
    }
}

void Frame::removeTaskButton(wxCommandEvent &event) {

    int selectedIndex = taskListBox->GetSelection();
    if (selectedIndex == wxNOT_FOUND) {
        wxMessageBox("Seleziona un task da eliminare!");
        return;
    } else {
        wxMessageDialog confirmDialog(this,
                                      "Sei sicuro di volerla eliminare?", "Conferma eliminazione",
                                      wxYES_NO | wxICON_QUESTION);

        int response = confirmDialog.ShowModal();

        if (response == wxID_YES) {
            itemController->removeTask(selectedIndex);
        }
    }
}

void Frame::editTaskButton(wxCommandEvent &event) {

    std::vector<Task> tasks = taskList->getVector();
    int selectedIndex = taskListBox->GetSelection();
    if (selectedIndex == wxNOT_FOUND) {
        wxMessageBox("Seleziona un task da modificare!");
        return;

    } else {
        TaskEditDialog editDialog(this, "Edit: ", tasks[selectedIndex].getTitle(),
                                  tasks[selectedIndex].getExpirationDate(), tasks[selectedIndex].getPriority());

        if (editDialog.ShowModal() == wxID_OK) {
            wxString taskName = editDialog.getTaskTitle();
            wxDateTime dateTime = editDialog.getExpirationDate();
            Priority newPriority = editDialog.getPriority();

            if (taskName.IsEmpty()) {
                wxMessageBox("Inserisci un task!");
                return;
            } else if (dateTime.IsEarlierThan(wxDateTime::Now() - wxTimeSpan::Days(1))) {
                wxMessageBox("Hai inserito una data passata!");
                return;
            } else if (newPriority != Priority::Low and newPriority != Priority::Medium and
                       newPriority != Priority::High) {
                wxMessageBox("Inserisci una priorità!");
                return;
            }

            itemController->editTask(selectedIndex, taskName, dateTime, newPriority);

        }
    }
}

void Frame::onTextChange(wxCommandEvent &event) {
    if (taskTextCtrl->GetLineLength(0) >= 1) {
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

void Frame::onSearchTextChange(wxCommandEvent &event) {
    if (searchInput->GetLineLength(0) >= 1) {
        wxString b = searchInput->GetValue();
        long pos = searchInput->GetInsertionPoint();
        wxString a = searchInput->GetRange(pos - 1, pos);
        b = b.Remove(pos - 1, 1);
        if (b.IsSameAs("Task Name", true)) {
            searchInput->ChangeValue(a);
            searchInput->SetDefaultStyle(wxTextAttr(*wxBLACK));
            searchInput->SetInsertionPointEnd();
        }
    }
}

void Frame::searchTaskButton(wxCommandEvent &event) {

    wxString searchKeyword = searchInput->GetValue();

    if (searchKeyword.IsSameAs("Task Name", true) || searchKeyword.IsEmpty()) {
        wxMessageBox("Inserisci un nome da cercare!");
        return;
    }
    std::vector<Task> temp = itemController->searchTask(searchKeyword); //restituisce il vettore dei cercati

    searchFrame(temp);
}

void Frame::searchFrame(std::vector<Task> tasks) {

    searchResultFrame = new wxFrame(frame, wxID_ANY, "Risultati della ricerca", wxDefaultPosition, wxDefaultSize);

    searchResultFrame->Bind(wxEVT_CLOSE_WINDOW, &Frame::CloseRefresh, this);
    auto searchResultSizer = new wxBoxSizer(wxVERTICAL);
    searchResultFrame->SetSizer(searchResultSizer);

    searchBox = new wxCheckListBox(searchResultFrame, ID_CheckSearch, wxDefaultPosition, wxDefaultSize, 0, nullptr,
                                   wxLB_SINGLE);

    searchResultSizer->Add(searchBox, 1, wxEXPAND | wxALL, 10);

    auto removeSearchButton = new wxButton(searchResultFrame, ID_RemoveSearch, "Remove Task");
    auto editSearchButton = new wxButton(searchResultFrame, ID_EditSearch, "Edit Task");
    auto buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    searchResultSizer->Add(removeSearchButton, 0, wxALL, 5);
    searchResultSizer->Add(editSearchButton, 0, wxALL, 5);
    searchResultSizer->Add(buttonSizer, 0, wxALIGN_RIGHT);

    showSearch(tasks);

    searchResultFrame->Show();
}

void Frame::showSearch(std::vector<Task> tasks) {

    for (int i = 0; i < tasks.size(); i++) {
        wxString priorityString;
        if (tasks[i].getPriority() == Priority::High) {
            priorityString = "HIGH";
        } else if (tasks[i].getPriority() == Priority::Medium) {
            priorityString = "MEDIUM";
        } else if (tasks[i].getPriority() == Priority::Low) {
            priorityString = "LOW";
        }
        wxString taskString = tasks[i].getTitle() + " - Priority: " + priorityString +
                              " - " + tasks[i].getExpirationDate().Format("%d %B, %Y");
        searchBox->Append(taskString);
        if (tasks[i].isCompleted()) {
            searchBox->Check(i, true);
        }
    }
}

void Frame::CloseRefresh(wxCloseEvent &event) {

    searchBox->Clear();
    event.Skip();
}

void Frame::editOfSearch(wxCommandEvent &event) {
    wxString searchKeyword = searchInput->GetValue();
    int i = 0;
    std::vector<Task> tasks = itemController->searchTask(searchKeyword);
    int selectedIndex = searchBox->GetSelection();
    if (selectedIndex == wxNOT_FOUND) {
        wxMessageBox("Seleziona un task da modificare!");
        return;
    } else {
        while (taskList->getVector()[i].getTitle() != tasks[selectedIndex].getTitle())
            i++;
    }

    TaskEditDialog editDialog(this, "Edit: ", tasks[selectedIndex].getTitle(),
                              tasks[selectedIndex].getExpirationDate(), tasks[selectedIndex].getPriority());

    if (editDialog.ShowModal() == wxID_OK) {
        wxString taskName = editDialog.getTaskTitle();
        wxDateTime dateTime = editDialog.getExpirationDate();
        Priority newPriority = editDialog.getPriority();

        if (taskName.IsEmpty()) {
            wxMessageBox("Inserisci un task!");
            return;
        } else if (dateTime.IsEarlierThan(wxDateTime::Now() - wxTimeSpan::Days(1))) {
            wxMessageBox("Hai inserito una data passata!");
            return;
        } else if (newPriority != Priority::Low and newPriority != Priority::Medium and
                   newPriority != Priority::High) {
            wxMessageBox("Inserisci una priorità!");
            return;
        }

        itemController->editTask(i, taskName, dateTime, newPriority);
    }

    searchBox->Clear();
    searchResultFrame->Close(true);
}

void Frame::removeOfSearch(wxCommandEvent &event) {

    wxString searchKeyword = searchInput->GetValue();
    int i = 0;
    std::vector<Task> tasks = itemController->searchTask(searchKeyword);
    int selectedIndex = searchBox->GetSelection();
    if (selectedIndex == wxNOT_FOUND) {
        wxMessageBox("Seleziona un task da rimuovere!");
        return;
    } else {
        while (taskList->getVector()[i].getTitle() != tasks[selectedIndex].getTitle())
            i++;
    }

    wxMessageDialog confirmDialog(searchResultFrame,
                                  "Sei sicuro di volerla eliminare?", "Conferma eliminazione",
                                  wxYES_NO | wxICON_QUESTION);

    int response = confirmDialog.ShowModal();

    if (response == wxID_YES) {
        itemController->removeTask(i);
    }

    searchBox->Clear();
    searchResultFrame->Close(true);
}

void Frame::checkSearch(wxCommandEvent &event) {

    wxString searchKeyword = searchInput->GetValue();
    int i = 0;
    std::vector<Task> tasks = itemController->searchTask(searchKeyword);
    int selectedIndex = event.GetSelection();
    while (taskList->getVector()[i].getTitle() != tasks[selectedIndex].getTitle())
        i++;

    if (searchBox->IsChecked(selectedIndex)) {

        itemController->markAsCompleted(i);

    } else if (!searchBox->IsChecked(selectedIndex)) {

        itemController->markAsCompleted(i);
    }
}

void Frame::sortByPriority(wxCommandEvent &event) {
    itemController->sortByPriority();
}

void Frame::sortByDate(wxCommandEvent &event) {
    itemController->sortByDate();
}

void Frame::sortByAlphabet(wxCommandEvent &event) {
    itemController->sortByAlphabet();
}

