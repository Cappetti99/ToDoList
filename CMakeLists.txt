cmake_minimum_required(VERSION 3.25)
project(ToDoList)

set(CMAKE_CXX_STANDARD 17)

# Find wxWidgets package
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

# Add executable target
add_executable(ToDoList main.cpp
        Task.cpp
        Task.h
        TaskList.cpp
        TaskList.h
        TaskView.cpp
        TaskView.h
        TaskListView.cpp
        TaskListView.h
        TaskListListView.cpp
        TaskListListView.h
        TaskListController.cpp
        TaskListController.h
        TaskListListController.cpp
        TaskListListController.h
        CustomWindow.cpp
        CustomWindow.h
        ToDoListApp.cpp
        ToDoListApp.h)

# Include wxWidgets headers
target_include_directories(ToDoList PRIVATE ${wxWidgets_INCLUDE_DIRS})

# Link against wxWidgets libraries
target_link_libraries(ToDoList PRIVATE ${wxWidgets_LIBRARIES})
