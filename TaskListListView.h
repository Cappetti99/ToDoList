//
// Created by cappe on 22/09/23.
//

#ifndef TODOLIST_TASKLISTLISTVIEW_H
#define TODOLIST_TASKLISTLISTVIEW_H

#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/listctrl.h>
#include <vector>
#include <wx/richtext/richtextctrl.h>
#include <wx/colour.h>
#include <wx/textctrl.h>
#include <wx/listbox.h>
#include <wx/checklst.h>


//#include "ToDoListApp.h"
#include "DateSelectionDialog.h"
#include "PrioritySelectionDialog.h"
#include "TaskListList.h"



class TaskListListView : public wxFrame {

public:
    TaskListListView(wxWindow* parent, const wxString& title, const wxPoint& pos, const wxSize& size);

    wxTextCtrl *getTaskTextCtrl() const;

    void setTaskTextCtrl(wxTextCtrl *taskTextCtrl);

    wxString & OnAddListButtonClick();

    void RefreshTaskList(std::vector<TaskList>* vector);

    wxButton *getAddListButton() const;

    const wxString &getTitle() const;

    void setTitle(const wxString &title);


    enum {
        ID_AddList = wxID_HIGHEST + 1,
        ID_RenameList,
        ID_RemoveList,
        ID_SearchList
    };
private:

    //TaskList *model;
    /*
    //funzioni
    void addListButton(wxCommandEvent& event);
    void removeListButton(wxCommandEvent& event);
    void searchListButton(wxCommandEvent& event);
    void renameListButton(wxCommandEvent& event);
    void openListButton(wxCommandEvent& event);
*/


    //variabili
    //TaskListListController controller;
    wxFrame frameListList;
    wxListBox* taskListList;



    std::vector<TaskList> lists;
    wxTextCtrl* taskTextCtrl;


    //bottoni
    wxButton* addListButton;
    wxButton* removeListButton;
    wxButton* searchListButton;
    wxButton* renameListButton;

    wxString title;




};

//todo quando premo un tasto deve andare da qualche parte, da fare questo


#endif //TODOLIST_TASKLISTLISTVIEW_H
