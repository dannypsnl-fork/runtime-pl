cmake_minimum_required(VERSION 3.10)

project(synthesizing)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

add_executable(synthesize src/main.cpp)
target_link_libraries(synthesize synthesize-lib)
target_include_directories(synthesize
        PRIVATE src)

# TEST
file(GLOB_RECURSE TEST_CODES test/*.cpp)
enable_testing()
find_package(GTest REQUIRED)
add_executable(tests ${TEST_CODES})
target_include_directories(tests
        PRIVATE src)
target_link_libraries(tests
        GTest::GTest GTest::Main
        synthesize-lib # This library
        )
add_test(
        NAME test
        COMMAND tests
)
