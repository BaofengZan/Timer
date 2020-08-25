cmake_minimum_required(VERSION 2.6)

project(timer)

add_definitions(-std=c++11)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)


add_executable(timer ${PROJECT_SOURCE_DIR}/Timer/main.cpp ${PROJECT_SOURCE_DIR}/Timer/CTimer.cpp ${PROJECT_SOURCE_DIR}/Timer/CTimer.h)
