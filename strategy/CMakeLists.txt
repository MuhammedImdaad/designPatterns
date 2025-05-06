cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(strategy VERSION 0.1.0 LANGUAGES C CXX)

add_executable(strategy main.cpp)

include_directories(.)