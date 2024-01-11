cmake_minimum_required(VERSION 3.27)
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
        Model/ToDoItem.cpp
        Model/ToDoItem.h
        Model/ToDoList.cpp
        Model/ToDoList.h
        Control/Control.cpp
        Control/Control.h
        View/View.cpp
        View/View.h
        View/Frame.cpp
        View/Frame.h
        Model/Model.cpp
        Model/Model.h
        Control/ItemController.cpp
        Control/ItemController.h
        Control/ListController.cpp
        Control/ListController.h
        View/DateSelection.cpp
        View/DateSelection.h
        View/PrioritySelection.cpp
        View/PrioritySelection.h
        View/Priority.h
        Model/Task.cpp
        Model/Task.h
        Control/ItemControllerObserver.h
)

# Include wxWidgets headers
target_include_directories(ToDoList PRIVATE ${wxWidgets_INCLUDE_DIRS})

# Link against wxWidgets libraries
target_link_libraries(ToDoList PRIVATE ${wxWidgets_LIBRARIES})


