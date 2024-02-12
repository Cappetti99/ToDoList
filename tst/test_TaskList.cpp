//
// Created by cappe on 13/12/23.
//
#include "gtest/gtest.h"
#include "/Users/mariavittoria/CLionProjects/ToDoList/src/Model/TaskList.h"

#include <wx/wx.h>

TEST(TodoListTest, AddTask) {
    TaskList *tasklist = new TaskList;
    tasklist->addTask("Task 1", wxDateTime::Today(), Priority::Low, false);
    std::vector<Task> tasks = tasklist->getVector();
    EXPECT_EQ(tasks.size(), 1);
}

TEST(TodoListTest, RemoveTask) {
    TaskList *tasklist = new TaskList;
    tasklist->addTask("Task 1", wxDateTime::Today(), Priority::Low, false);
    tasklist->removeTask(0);
    std::vector<Task> tasks = tasklist->getVector();
    EXPECT_EQ(tasks.size(), 0);
}

TEST(TodoListTest, MarkTaskCompleted) {
    TaskList *tasklist = new TaskList;
    tasklist->addTask("Task 1", wxDateTime::Today(), Priority::Low, false);
    tasklist->setTaskAsCompleted(0);
    std::vector<Task> tasks = tasklist->getVector();
    EXPECT_TRUE(tasks[0].isCompleted());
}

TEST(TodoListTest, EditTaskName) {
    TaskList *tasklist = new TaskList;
    tasklist->addTask("Task 1", wxDateTime::Today(), Priority::Low, false);
    tasklist->editTask(0, "Nuovo Nome", wxDateTime::Today(), Priority::Low);
    std::vector<Task> tasks = tasklist->getVector();
    bool found;
    for (int i = 0; i <= tasks.size(); i++) {
        if (tasks[i].getTitle() == "Nuovo Nome") {
            found = true;
        }
    }
    EXPECT_TRUE(found);
}

TEST(TodoListTest, EditTaskPriority) {
    TaskList *tasklist = new TaskList;
    tasklist->addTask("Task 1", wxDateTime::Today(), Priority::Medium, false);
    tasklist->editTask(0, "Task 1", wxDateTime::Today(), Priority::High);
    std::vector<Task> tasks = tasklist->getVector();
    bool found;
    for (int i = 0; i <= tasks.size(); i++) {
        if (tasks[i].getPriority() == Priority::High) {
            found = true;
        }
    }
    EXPECT_TRUE(found);
}

TEST(TodoListTest, EditTaskDate) {
    TaskList *tasklist = new TaskList;
    tasklist->addTask("Task 1", wxDateTime::Today(), Priority::Medium, false);
    tasklist->editTask(0, "Task 1", wxDateTime::Today().SetYear(2025), Priority::Medium);
    std::vector<Task> tasks = tasklist->getVector();
    bool found= false;
    for (int i = 0; i <= tasks.size(); i++) {
        if (tasks[i].getExpirationDate() == wxDateTime::Today()) {
            found = true;
        }
    }
    EXPECT_FALSE(found);
}

TEST(TodoListTest, completedTask) {
    TaskList *tasklist = new TaskList;
    tasklist->addTask("Task 1", wxDateTime::Today(), Priority::Low, false);
    tasklist->addTask("Task 2", wxDateTime::Today(), Priority::Low, true);
    EXPECT_EQ(tasklist->completedTask(), 1);
}

TEST(TodoListTest, ExpiringTask) {
    TaskList *tasklist = new TaskList;
    tasklist->addTask("Task 1", wxDateTime::Today(), Priority::Low, false);
    EXPECT_EQ(tasklist->getExpiringTask().size(),1);
}

TEST(TodoListTest,ImportantTask){
    TaskList *tasklist = new TaskList;
    tasklist->addTask("Task 1", wxDateTime::Today(), Priority::High, false);
    EXPECT_EQ(tasklist->getImportantTask().size(),1);
}