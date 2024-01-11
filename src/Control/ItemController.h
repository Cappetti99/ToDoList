//
// Created by cappe on 18/12/23.
//

#ifndef LOLLO_ITEMCONTROLLER_H
#define LOLLO_ITEMCONTROLLER_H

#include <wx/wx.h>
#include <iostream>

#include "../Model/ToDoItem.h"
#include "../View/Frame.h"
#include "ItemControllerObserver.h"


class ItemController : public ItemControllerObserver {

public:
    ItemController();

    void addItem(wxString name, wxDateTime date, Priority priority);

    void removeItem(int index);

    void markItemAsCompleted();

    void searchItem(wxString searchKeyword);

    virtual void onAddTaskButtonClicked() override;

    virtual void onRemoveTaskButtonClicked(int index) override;

    virtual void onSearchTaskButtonClicked(wxString searchKeyword) override;

    void showTask(wxString name, wxDateTime date, Priority priority);

    void removeFrame(int index);

private:
    Frame *frame;
    ToDoItem *item;

};


#endif //LOLLO_ITEMCONTROLLER_H
