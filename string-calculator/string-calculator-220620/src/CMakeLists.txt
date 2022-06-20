cmake_minimum_required(VERSION 3.21)
project(string_calculator)

set(SOURCE_FILES
        calculator.cpp
        calculator.h)

add_library(${PROJECT_NAME} ${SOURCE_FILES})