# CMakeLists.txt for YourProjectName

cmake_minimum_required(VERSION 3.27)
project(Lollo CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the path to Google Test headers
include_directories(${CMAKE_SOURCE_DIR}/path/to/googletest/googletest/include)

# Add subdirectory containing the Google Test source code
add_subdirectory(path/to/googletest/googletest)

# Find wxWidgets package
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

# Your source files
set(SOURCES
        src/main.cpp
        # Add your other source files here
)

# Your header files
#set(HEADERS
#        include/Lollo/ToDoItem.h
#        include/Lollo/ToDoList.h
#        # Add your other header files here
#)

# Your test files
set(TEST_SOURCES
        tests/test_main.cpp
        tests/test_ToDoItem.cpp
        tests/test_ToDoList.cpp
        # Add your other test files here
)

# Create the main executable
add_executable(Lollo ${SOURCES} ${HEADERS})

# Link the main executable with wxWidgets
target_link_libraries(YourProjectName ${wxWidgets_LIBRARIES})

# Link the main executable with Google Test
target_link_libraries(Lollo gtest_main)

# Link the test executable with Google Test and wxWidgets
target_link_libraries(YourProjectNameTests gtest gtest_main ${wxWidgets_LIBRARIES})

# Create the test executable
add_executable(LolloTests ${TEST_SOURCES} ${HEADERS})

# Link the test executable with Google Test
target_link_libraries(LolloTests gtest gtest_main)

# Optionally, you can add a custom target to run the tests
add_custom_target(run_tests COMMAND LolloTests DEPENDS LolloTests)

# If you want to use 'make test' to run your tests, uncomment the following lines
# include(CTest)
# add_test(NAME YourProjectNameTests COMMAND YourProjectNameTests)


#da riguardare perchè non so se fa