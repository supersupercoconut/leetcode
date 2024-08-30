cmake_minimum_required(VERSION 3.27)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)


add_executable(leetcode
        main.cpp
        leetcode.h
        stdc.h)
