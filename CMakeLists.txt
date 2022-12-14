cmake_minimum_required(VERSION 3.24)
project(libGUI)
set(CMAKE_CXX_STANDARD 11)
file(GLOB SOURCES
        *.h
        *.cpp
        )
add_executable(libGUI source/3dsmain.cpp)