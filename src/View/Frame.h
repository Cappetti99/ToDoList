//
// Created by cappe on 14/12/23.
//

#ifndef LOLLO_FRAME_H
#define LOLLO_FRAME_H

#include <wx/wx.h>

#include "DateSelection.h"
#include "PrioritySelection.h"
#include "../Control/ItemControllerObserver.h"

class Frame : public wxFrame {

public:
    Frame(const wxString &title, const wxPoint &pos, const wxSize &size, ItemControllerObserver *observer);

    wxString getNames();

    wxDateTime getDates();

    Priority getPriorities();

    ItemControllerObserver *observer;

    void showTaskFrame(wxString name, wxDateTime date, Priority priority);

    void showSearchFrame(std::vector<wxString> namesSearch, std::vector<wxDateTime> datesSearch,
                         std::vector<Priority> prioritiesSearch);

    void removeTaskFrame(int index);

    void refreshTaskFrame();

    void ClearFrame();


    void CloseRefresh(wxCloseEvent& event);

wxDECLARE_EVENT_TABLE();

private:
    //gestione bottoni
    //devono essere private?
    void addTaskButton(wxCommandEvent &event);

    void removeTaskButton(wxCommandEvent &event);

    void searchTaskButton(wxCommandEvent &event);


    wxTextCtrl *taskTextCtrl;
    std::vector<wxString> names;
    std::vector<wxDateTime> dates;
    std::vector<Priority> priorities;
    wxListBox *taskListBox;
    wxTextCtrl *searchInput;
    wxWindow *frame;

    std::vector<wxString> namesSearch;
    std::vector<wxDateTime> datesSearch;
    std::vector<Priority> prioritiesSearch;

};


enum {
    ID_AddTaskButton = 1,
    ID_RemoveTaskButton = 2,
    ID_SearchTaskButton = 3,
    ID_SortTaskButton = 4
};

#endif //LOLLO_FRAME_H
