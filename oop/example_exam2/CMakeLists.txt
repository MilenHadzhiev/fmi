cmake_minimum_required(VERSION 3.30)
project(example_exam2)

set(CMAKE_CXX_STANDARD 20)

add_executable(example_exam2 main.cpp
        article/Article.cpp
        article/Article.h
        report/Report.cpp
        report/Report.h
        DynamicArray/DynamicArray.h
        Author/Author.h)
