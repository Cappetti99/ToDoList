# TodoList Application

## Introduction
This is a simple TodoList application written in C++ using the wxWidgets library. The application follows the MVC (Model-View-Controller) architecture and utilizes the Observer design pattern for efficient task management.

## Features
- Add, edit, and delete tasks
- Mark tasks as completed

## Architecture
The application is designed using the Model-View-Controller (MVC) architecture, which separates the internal representation of information (Model), the presentation of the user interface (View), and the handling of user input (Controller). This design promotes modularity and maintainability.

Additionally, the Observer design pattern is employed to enable efficient communication between components. The model notifies the view(s) of any changes, ensuring that the user interface remains synchronized with the underlying data.

## Requirements
- C++ compiler
- wxWidgets library 

