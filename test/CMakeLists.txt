cmake_minimum_required(VERSION 3.10)

project(ToDoList)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(./lib/googletest)

set(gtest_SOURCE_DIR, ./lib/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp test_TaskList.cpp test_Frame.cpp)

add_executable(runAllTests ${TEST_SOURCE_FILES})

target_link_libraries(runAllTests gtest gtest_main core)

# Add the path to Google Test
#add_subdirectory(path/to/googletest)
#
## Add your source files
#add_executable(YourExecutableName
#        src/ToDoApp.cpp
#        # Add other source files here
#)
#
## Add your test files
#add_executable(YourTests
#        test_main.cpp
#        test_Frame.cpp
#        test_TaskList.cpp
#)
#
## Link Google Test to your test executable
#target_link_libraries(YourTests gtest gtest_main)
#
## Optionally, link your main executable to Google Test for testing private functions
#target_link_libraries(YourExecutableName gtest gtest_main)
#
## Optionally, enable testing with CTest
#include(GoogleTest)
#gtest_discover_tests(YourTests)
