cmake_minimum_required(VERSION 3.10)

project(synthesizing)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

add_executable(synthesize src/main.cpp)
target_link_libraries(synthesize synthesize-lib)
