add_test([=[TodoListTest.AddTask]=]  /home/cappe/CLionProjects/ToDoList/test_e/cmake-build-debug/test_TaskList [==[--gtest_filter=TodoListTest.AddTask]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TodoListTest.AddTask]=]  PROPERTIES WORKING_DIRECTORY /home/cappe/CLionProjects/ToDoList/test_e/cmake-build-debug SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[TodoListTest.RemoveTask]=]  /home/cappe/CLionProjects/ToDoList/test_e/cmake-build-debug/test_TaskList [==[--gtest_filter=TodoListTest.RemoveTask]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TodoListTest.RemoveTask]=]  PROPERTIES WORKING_DIRECTORY /home/cappe/CLionProjects/ToDoList/test_e/cmake-build-debug SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[TodoListTest.MarkTaskCompleted]=]  /home/cappe/CLionProjects/ToDoList/test_e/cmake-build-debug/test_TaskList [==[--gtest_filter=TodoListTest.MarkTaskCompleted]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TodoListTest.MarkTaskCompleted]=]  PROPERTIES WORKING_DIRECTORY /home/cappe/CLionProjects/ToDoList/test_e/cmake-build-debug SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[TodoListTest.EditTaskName]=]  /home/cappe/CLionProjects/ToDoList/test_e/cmake-build-debug/test_TaskList [==[--gtest_filter=TodoListTest.EditTaskName]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TodoListTest.EditTaskName]=]  PROPERTIES WORKING_DIRECTORY /home/cappe/CLionProjects/ToDoList/test_e/cmake-build-debug SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[TodoListTest.EditTaskPriority]=]  /home/cappe/CLionProjects/ToDoList/test_e/cmake-build-debug/test_TaskList [==[--gtest_filter=TodoListTest.EditTaskPriority]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TodoListTest.EditTaskPriority]=]  PROPERTIES WORKING_DIRECTORY /home/cappe/CLionProjects/ToDoList/test_e/cmake-build-debug SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[TodoListTest.EditTaskDate]=]  /home/cappe/CLionProjects/ToDoList/test_e/cmake-build-debug/test_TaskList [==[--gtest_filter=TodoListTest.EditTaskDate]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TodoListTest.EditTaskDate]=]  PROPERTIES WORKING_DIRECTORY /home/cappe/CLionProjects/ToDoList/test_e/cmake-build-debug SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[TodoListTest.completedTask]=]  /home/cappe/CLionProjects/ToDoList/test_e/cmake-build-debug/test_TaskList [==[--gtest_filter=TodoListTest.completedTask]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TodoListTest.completedTask]=]  PROPERTIES WORKING_DIRECTORY /home/cappe/CLionProjects/ToDoList/test_e/cmake-build-debug SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[TodoListTest.ExpiringTask]=]  /home/cappe/CLionProjects/ToDoList/test_e/cmake-build-debug/test_TaskList [==[--gtest_filter=TodoListTest.ExpiringTask]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TodoListTest.ExpiringTask]=]  PROPERTIES WORKING_DIRECTORY /home/cappe/CLionProjects/ToDoList/test_e/cmake-build-debug SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[TodoListTest.ImportantTask]=]  /home/cappe/CLionProjects/ToDoList/test_e/cmake-build-debug/test_TaskList [==[--gtest_filter=TodoListTest.ImportantTask]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TodoListTest.ImportantTask]=]  PROPERTIES WORKING_DIRECTORY /home/cappe/CLionProjects/ToDoList/test_e/cmake-build-debug SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  test_TaskList_TESTS TodoListTest.AddTask TodoListTest.RemoveTask TodoListTest.MarkTaskCompleted TodoListTest.EditTaskName TodoListTest.EditTaskPriority TodoListTest.EditTaskDate TodoListTest.completedTask TodoListTest.ExpiringTask TodoListTest.ImportantTask)