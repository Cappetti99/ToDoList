//
// Created by cappe on 14/12/23.
//

#ifndef TODOLIST_FRAME_H
#define TODOLIST_FRAME_H

#include <wx/wx.h>

#include "DateSelectionDialog.h"
#include "PrioritySelectionDialog.h"
#include "View.h"
#include "../Control/ItemController.h"

class Frame : public View, public wxFrame {

public:
    Frame(ToDoItem *toDoItem, ItemController *itemController, const wxString &title, const wxPoint &pos, const wxSize &size);

    ~Frame() override;

    //metodi di Observer
    void update() override;

    //metodi di View
    void show() override;

    void addTaskButton(wxCommandEvent &event);

    void checkTaskButton(wxCommandEvent &event);



private:
    ToDoItem *toDoItem;
    ItemController *itemController;


//    void showTaskFrame(wxString name, wxDateTime date, Priority priority, bool completed, int index);
//
//    void showSearchFrame(std::vector<wxString> namesSearch, std::vector<wxDateTime> datesSearch,
//                         std::vector<Priority> prioritiesSearch, std::vector<bool> completedSearch,
//                         std::vector<wxString> allNames,
//                         std::vector<wxDateTime> allDates, std::vector<Priority> allPriorities,
//                         std::vector<bool> allCompleted);
//
//    void ClearFrame();
//
//    void CloseRefresh(wxCloseEvent &event);


//    const wxString &getNome() const;
//
//    const wxDateTime &getData() const;

//    Priority getPriorità() const;


//    ItemControllerObserver *observer; //dovrebbe diventare inutile


wxDECLARE_EVENT_TABLE();

private:
    //gestione bottoni

//    void removeTaskButton(wxCommandEvent &event);
//
//    void searchTaskButton(wxCommandEvent &event);
//
//    void checkTaskButton(wxCommandEvent &event);
//
//    void editTaskButton(wxCommandEvent &event);
//
//    void removeSearchButton(wxCommandEvent &event);
//
//    void onTextChange(wxCommandEvent &event);
//
//    void onTextClick(wxCommandEvent &event);
//
//    void onSearchTextChange(wxCommandEvent &event);
//
//    void searchShow(std::vector<wxString> namesSearch, std::vector<wxDateTime> datesSearch,
//                    std::vector<Priority> prioritiesSearch, std::vector<bool> completedSearch);
//
//    void updateVector(std::vector<wxString> names, std::vector<wxDateTime> dates,
//                      std::vector<Priority> priorities, std::vector<bool> completed);
//


    wxTextCtrl *taskTextCtrl;
    wxString Nome;
    wxDateTime Data;
    Priority Priorità;

    std::vector<wxString> names;
    std::vector<wxDateTime> dates;
    std::vector<Priority> priorities;
    std::vector<bool> completed;
    wxCheckListBox *taskListBox;
    wxTextCtrl *searchInput;
    wxWindow *frame;
    wxFrame *searchResultFrame;

    std::vector<wxString> namesSearch;
    std::vector<wxDateTime> datesSearch;
    std::vector<Priority> prioritiesSearch;
    std::vector<bool> completedSearch;

    std::vector<wxString> allTask;

    wxCheckListBox *searchBox;

//importante
    Model *model;
    Control *control;

};


enum {
    ID_AddTaskButton = 1,
    ID_RemoveTaskButton = 2,
    ID_SearchTaskButton = 3,
    ID_RemoveSearch = 4,
    ID_Check = 5,
    ID_TextCtrl = 6,
    ID_SearchText = 7,
    ID_EditTaskButton = 8
};

#endif //TODOLIST_FRAME_H