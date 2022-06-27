cmake_minimum_required(VERSION 3.21)
project(string_calculator_220627)

set(CMAKE_CXX_STANDARD 11)

add_executable(string_calculator_220627 main.cpp)

enable_testing()

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)