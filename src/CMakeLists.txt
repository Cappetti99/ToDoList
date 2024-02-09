cmake_minimum_required(VERSION 3.25.2)
project(ToDoList)

set(CMAKE_CXX_STANDARD 17)

set( CMAKE_BUILD_TYPE Debug )
# Find wxWidgets package
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

# Add executable target
add_executable(ToDoList main.cpp
        ToDoApp.cpp
        ToDoApp.h
        Model/TaskList.cpp
        Model/TaskList.h
        Control/Control.cpp
        Control/Control.h
        View/Frame.cpp
        View/Frame.h
        Control/ItemController.cpp
        Control/ItemController.h
        View/DateSelectionDialog.cpp
        View/DateSelectionDialog.h
        View/PrioritySelectionDialog.cpp
        View/PrioritySelectionDialog.h
        View/Priority.h
        Model/Task.cpp
        Model/Task.h
        View/View.cpp
        View/View.h
        Model/Model.cpp
        Model/Model.h
        Observer.cpp
        Observer.h
        Subject.cpp
        Subject.h
        View/TaskEditDialog.cpp
        View/TaskEditDialog.h
)

# Include wxWidgets headers
target_include_directories(ToDoList PRIVATE ${wxWidgets_INCLUDE_DIRS})

# Link against wxWidgets libraries
target_link_libraries(ToDoList PRIVATE ${wxWidgets_LIBRARIES})


