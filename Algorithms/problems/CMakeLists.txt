cmake_minimum_required(VERSION 3.30)
project(problems)

set(CMAKE_CXX_STANDARD 20)

add_executable(problems main.cpp
        smallest_infinite_set/smallest_infinite_set.h
        sorts/mergesort.h
        linked_lists/mergesort.h)
