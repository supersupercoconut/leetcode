cmake_minimum_required(VERSION 3.27)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)


add_executable(leetcode
        ./leetcode/editor/cn/leetcode_num_77.cpp
        leetcode.h
        stdc.h)

add_executable(Other
        Other/arraySort.cpp)

add_executable(Train
#        Train/Train01.cpp
        Train/Train02.cpp)

add_executable(KMW
#        KMW/KMW_99.cpp)
        KMW/KMW_126.cpp)