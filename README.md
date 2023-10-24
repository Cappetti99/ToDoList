# ToDoList

auto values =view->OnAddListButtonClick();
wxDateTime a = std::get<0>(values);
wxString b =std::get<1>(values);
Priority c =std::get<2>(values);

       //model->addList();
       model->addTask1(a,b,c);