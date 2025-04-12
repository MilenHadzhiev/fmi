cmake_minimum_required(VERSION 3.30)
project(example_exam1)

set(CMAKE_CXX_STANDARD 20)

add_executable(example_exam1 main.cpp
        Task/Task.cpp
        Task/Task.h
        MonthlyPlanner/MonthlyPlanner.cpp
        MonthlyPlanner/MonthlyPlanner.h
        PlannedTask/PlannedTask.cpp
        PlannedTask/PlannedTask.h)
