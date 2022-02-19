cmake_minimum_required (VERSION 3.12)

project(helloducktape LANGUAGES CXX)
set(executable_name "helloducktape")

add_executable(helloducktape main.cpp)

set(DTROOT "${PROJECT_SOURCE_DIR}/Ducktape/")
set(PROJECT helloducktape)
include(${DTROOT}/cmake/ducktape.cmake)