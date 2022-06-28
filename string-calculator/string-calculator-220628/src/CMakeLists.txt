cmake_minimum_required(VERSION 3.12)

project(string_calculator)

set(SOURCE_FILES
        Calculator.h
        Calculator.cpp)

add_library(${PROJECT_NAME} ${SOURCE_FILES})