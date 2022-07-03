cmake_minimum_required(VERSION 3.21)
project(string_calculator_220703)

set(CMAKE_CXX_STANDARD 14)

add_executable(string_calculator_220703 main.cpp)

enable_testing()

include_directories(source)
add_subdirectory(source)
add_subdirectory(test)
