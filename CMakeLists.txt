cmake_minimum_required(VERSION 3.15)

project(cmor C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set (SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set (INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE BOOL "" FORCE)

file(GLOB SOURCES "${SRC_DIR}/*.c")

add_library(cmor SHARED ${SOURCES})

target_include_directories(cmor PUBLIC ${INCLUDE_DIR})