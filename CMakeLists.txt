cmake_minimum_required(VERSION 3.3)
project(StringLibrary)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp WordIndex.cpp)
add_executable(StringLibrary ${SOURCE_FILES})