cmake_minimum_required(VERSION 3.0.0)

project(LibEventTesting)

include(CTest)

set (CMAKE_CXX_STANDARD 11)

add_executable(LibEventTests LibEventTests.cpp)
include_directories(../)

add_test(NAME LibEventPublishTest COMMAND LibEventTests)