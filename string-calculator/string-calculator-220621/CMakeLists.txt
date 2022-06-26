cmake_minimum_required(VERSION 3.21)
project(string_calculator_220621)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

enable_testing()

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)

target_link_libraries(${PROJECT_NAME} string_calculator)
