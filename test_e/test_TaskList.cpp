//
// Created by cappe on 13/12/23.
//
#include "gtest/gtest.h"
#include "/home/cappe/CLionProjects/ToDoList/src/Model/TaskList.h"

#include <wx/wx.h>

TEST(TodoListTest, AddTask) {
    TaskList *tasklist = new TaskList;
    tasklist->addTask("Task 1", wxDateTime::Today(), Priority::Low, false);
    EXPECT_EQ(tasklist->CountTask(), 1);
}

TEST(TodoListTest, RemoveTask) {
    TaskList *tasklist = new TaskList;
    tasklist->addTask("Task 1", wxDateTime::Today(), Priority::Low, false);
    tasklist->removeTask(0);
    tasklist->removeTask(12);
    EXPECT_EQ(tasklist->CountTask(), 0);
}

TEST(TodoListTest, MarkTaskCompleted) {
    TaskList *tasklist = new TaskList;
    tasklist->addTask("Task 1", wxDateTime::Today(), Priority::Low, false);
    tasklist->setTaskAsCompleted(0);
    bool found = false;
    if(tasklist->completedTask() ==1){
        found = true;
    }
    EXPECT_TRUE(found);
}

TEST(TodoListTest, TrueToFalse){
    TaskList *tasklist = new TaskList;
    tasklist->addTask("Task 1", wxDateTime::Today(), Priority::Low, true);
    tasklist->setTaskAsCompleted(0);
    bool found = false;
    if(tasklist->completedTask() ==1){
        found = true;
    }
    EXPECT_FALSE(found);
}

TEST(TodoListTest, EditTaskName) {
    TaskList *tasklist = new TaskList;
    tasklist->addTask("Task 1", wxDateTime::Today(), Priority::Low, false);
    tasklist->editTask(0, "Nuovo Nome", wxDateTime::Today(), Priority::Low);

    bool found = false;

    if (tasklist->Search("Nuovo Nome").size()== 1){
        found = true;
    }
    EXPECT_TRUE(found);
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
