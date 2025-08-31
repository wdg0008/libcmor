cmake_minimum_required(VERSION 3.15)

project(libcmor C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set (SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set (INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")

file(GLOB SOURCES "${SRC_DIR}/*.c")

add_library(libcmor STATIC ${SOURCES})

target_include_directories(libcmor PUBLIC ${INCLUDE_DIR})