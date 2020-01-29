cmake_minimum_required(VERSION 3.10)

project(z3_c++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(z3_find.cmake)
find_z3()
add_executable(example main.cpp)
target_include_directories(example PRIVATE ${Z3_INCLUDE_DIRS})
target_link_libraries(example PRIVATE ${Z3_LIBRARIES})
