cmake_minimum_required(VERSION 3.28)
project(C867_PA)

set(CMAKE_CXX_STANDARD 17)

include_directories(SYSTEM .)

add_executable(C867_PA main.cpp
        roster.h
        student.h
        degree.h
        student.cpp
        roster.cpp
        degree.h
        roster.h
        student.h)
