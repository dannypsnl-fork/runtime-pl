project(src)

find_library(Z3_LIBRARIES
        NAMES z3
        DOC "Z3 libraries"
        REQUIRED)
if (Z3_LIBRARIES)
    message(STATUS "Found Z3 libraries: \"${Z3_LIBRARIES}\"")
else()
    message(STATUS "Could not find Z3 libraries")
endif()
find_path(Z3_INCLUDE_DIRS
        NAMES z3.h
        PATH_SUFFIXES z3
        DOC "Z3 C header"
        )
if (Z3_INCLUDE_DIRS)
    message(STATUS "Found Z3 include path: \"${Z3_INCLUDE_DIRS}\"")
else()
    message(STATUS "Could not find Z3 include path")
endif()

add_library(synthesize-lib Program.h Program.cpp Instruction.cpp Instruction.h ProgramBuilder.cpp ProgramBuilder.h Component.h Specification.h)
# Link Z3
target_include_directories(synthesize-lib PRIVATE ${Z3_INCLUDE_DIRS})
target_link_libraries(synthesize-lib PRIVATE ${Z3_LIBRARIES})
