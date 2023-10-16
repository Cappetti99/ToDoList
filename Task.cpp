#include "Task.h"

Task::Task(const wxString &title, Priority priority, bool completed, const wxDateTime &expirationDate)
        : title(title), priority(priority), completed(completed), expirationDate(expirationDate) {}

// Implement getter and setter methods for Task attributes
const wxString &Task::getTitle() const {
    return title;
}

void Task::setTitle(const wxString &title) {
    this->title = title;
}

Priority Task::getPriority() const {
    return priority;
}

void Task::setPriority(Priority priority) {
    this->priority = priority;
}

bool Task::isCompleted() const {
    return completed;
}

void Task::setCompleted(bool completed) {
    this->completed = completed;
}

const wxDateTime &Task::getExpirationDate() const {
    return expirationDate;
}

void Task::setExpirationDate(const wxDateTime &expirationDate) {
    this->expirationDate = expirationDate;
}

// Static method to convert Priority enum to string
wxString Task::PriorityToString(Priority priority) {
    switch (priority) {
        case Priority::Low:
            return "Low";
        case Priority::Medium:
            return "Medium";
        case Priority::High:
            return "High";
        default:
            return "";
    }
}

void Task::addTask() {

    printf("jj");
    wxString title = wxGetTextFromUser("Enter title:");
    //si potrebbe prendere il nome della task una volta pigiato add?

    DateSelectionDialog dateDialog(nullptr, "Select expiration date:");

    if (dateDialog.ShowModal() == wxID_OK) {
        wxDatePickerCtrl *datePicker = dateDialog.getDatePicker();
        wxDateTime expirationDate = datePicker->GetValue();
        wxString expirationDateStr = expirationDate.Format("%d %B, %Y");

        Task newTask;
        newTask.setTitle(title);
        newTask.setCompleted(false);
        newTask.setExpirationDate(expirationDate);

        PrioritySelectionDialog priorityDialog(nullptr, "Select priority:");

        if (priorityDialog.ShowModal() == wxID_OK) {
            Priority selectedPriority = priorityDialog.getSelectedPriority();
            newTask.setPriority(selectedPriority);


            taskList.push_back(newTask);

        }

        refreshTask();

        printf(title);
        printf(expirationDateStr); //questi print mi servono per verificare se funziona perchè non mi riesce printare sulla schermata

    }
}

void Task::removeTask() {

}

void Task::sortTask() {

}

std::vector<Task> Task::searchTask() {
    return std::vector<Task>();
}

void Task::swapTask() {

}

void Task::refreshTask() {
    for (const Task &task: taskList) {
        wxString priorityStr;

        switch (task.getPriority()) {
            case Priority::Low:
                priorityStr = "* Low";
                break;
            case Priority::Medium:
                priorityStr = "** Medium";
                break;
            case Priority::High:
                priorityStr = "*** High";
                break;
        }

        int index = 0;
        Task selected = task;
        for (int i = 0; i < taskList.size(); ++i) {
            if (taskList[i].getTitle() == selected.getTitle() &&
                taskList[i].getExpirationDate() == selected.getExpirationDate()) {
                index = i;
                break;
            }
        }


        wxString taskString = task.getTitle() + " - Priority: " + priorityStr +
                              " - " + task.getExpirationDate().Format("%d %B, %Y");

        if (task.isCompleted())
            taskString += " - Completed";


//        getTaskCheckBox.Append(taskString);
//        if (task.isCompleted())
//            taskCheckBox->Check(index,true);

    }

}
