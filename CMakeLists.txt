cmake_minimum_required(VERSION 3.20)
project(leetcode_cplusplus)

set(CMAKE_CXX_STANDARD 23)

add_executable(leetcode_cplusplus main.cpp MoveZeroesSolution.cpp MoveZeroesSolution.h)
add_executable(remove_linked_list_elements remove_linked_list_elements/main.cpp)
add_executable(easy_in_disguise easy_in_disguise/main.cpp)
