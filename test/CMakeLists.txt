cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 14)


add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest)

include_directories(${gtest_SOURCE_DIR} /include ${gtest_SOURCE_DIR})
set(TEST_SOURCE_FILES MyTest.cpp)
add_executable(Test ${TEST_SOURCE_FILES})

target_link_libraries(Test gtest gtest_main core)
#serve a me per google test credo
include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)