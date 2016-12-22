cmake_minimum_required(VERSION 3.6)
project(GenAlg)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ind.h pop.h)
add_executable(GenAlg ${SOURCE_FILES})