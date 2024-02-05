//
// Created by cappe on 14/12/23.
//

#ifndef TODOLIST_FRAME_H
#define TODOLIST_FRAME_H

#include <wx/wx.h>

#include "DateSelectionDialog.h"
#include "PrioritySelectionDialog.h"
#include "TaskEditDialog.h"
#include "View.h"
#include "../Control/ItemController.h"

class Frame : public View, public wxFrame {

public:
    Frame(TaskList *taskList, ItemController *itemController, const wxString &title, const wxPoint &pos, const wxSize &size);

    ~Frame() override;

    //metodi di Observer
    void update() override;

    //metodi di View
    void show() override;

    void addTaskButton(wxCommandEvent &event);

    void checkTaskButton(wxCommandEvent &event);

    void removeTaskButton(wxCommandEvent &event);

    void editTaskButton(wxCommandEvent &event);

    void onTextChange(wxCommandEvent &event);

    void editMouse(wxMouseEvent &event);

//    void showTaskFrame(wxString name, wxDateTime date, Priority priority, bool completed, int index);
//
//    void showSearchFrame(std::vector<wxString> namesSearch, std::vector<wxDateTime> datesSearch,
//                         std::vector<Priority> prioritiesSearch, std::vector<bool> completedSearch,
//                         std::vector<wxString> allNames,
//                         std::vector<wxDateTime> allDates, std::vector<Priority> allPriorities,
//                         std::vector<bool> allCompleted);
//
//    void CloseRefresh(wxCloseEvent &event);

wxDECLARE_EVENT_TABLE();

private:

    wxTextCtrl *taskTextCtrl;
    wxCheckListBox *taskListBox;
    wxTextCtrl *searchInput;
    wxWindow *frame;
    wxFrame *searchResultFrame;

    wxCheckListBox *searchBox;

//importante
    Model *model;
    Control *control;
    TaskList *taskList;
    ItemController *itemController;
};

enum {
    ID_AddTaskButton = 1,
    ID_RemoveTaskButton = 2,
    ID_SearchTaskButton = 3,
    ID_RemoveSearch = 4,
    ID_Check = 5,
    ID_TextCtrl = 6,
    ID_SearchText = 7,
    ID_EditTaskButton = 8,
    ID_Mouse = 9
};

#endif //TODOLIST_FRAME_H