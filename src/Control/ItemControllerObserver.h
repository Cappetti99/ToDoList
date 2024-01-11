//
// Created by cappe on 30/12/23.
//

#ifndef LOLLO_ITEMCONTROLLEROBSERVER_H
#define LOLLO_ITEMCONTROLLEROBSERVER_H


class ItemControllerObserver {

public:
    virtual void onAddTaskButtonClicked() = 0;
    virtual void onRemoveTaskButtonClicked(int index) = 0;
    virtual void onSearchTaskButtonClicked(wxString searchKeyword) = 0;
    //virtual void onEditTaskButtonClicked() = 0;

};


#endif //LOLLO_ITEMCONTROLLEROBSERVER_H
