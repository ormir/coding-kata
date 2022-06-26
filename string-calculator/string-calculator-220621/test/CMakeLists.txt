cmake_minimum_required(VERSION 3.21)

project(string_calculator_test)

set(SOURCE_FILES
        CalculatorTests.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

add_subdirectory(libs/googletest-release-1.11.0)

target_link_libraries(${PROJECT_NAME}
        gtest_main
        string_calculator)