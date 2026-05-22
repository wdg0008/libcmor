cmake_minimum_required(VERSION 3.15)

project(cmor C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set (SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set (INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE BOOL "" FORCE)

# collect all the library implementation files
file(GLOB SOURCES "${SRC_DIR}/*.c")

# generate an object library to avoid recompiling both shared and static libraries
add_library(cmor_obj OBJECT ${SOURCES})
target_include_directories(cmor_obj PUBLIC ${INCLUDE_DIR})

# link together the shared library
add_library(cmor_shared SHARED)
target_link_libraries(cmor_shared PUBLIC cmor_obj)

# link together the static library
add_library(cmor_static STATIC)
target_link_libraries(cmor_static PUBLIC cmor_obj)