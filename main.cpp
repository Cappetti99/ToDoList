
#include <wx/wx.h>

#include "TaskListView.h"
#include "TaskListListView.h"
#include "TaskListController.h"
#include "TaskListListController.h"
#include "CustomWindow.h"
//E' TUTTO DA SISTEMARE
int main(){
/*class ToDoListApp : public wxApp {
public:

    */
wxApp::SetInstance(new wxApp);
wxApp::GetInstance()->OnInit();
TaskList model;
TaskListListView();
TaskListListController controller(&model, &view);

view.Show(true);
controller.Run();



};

