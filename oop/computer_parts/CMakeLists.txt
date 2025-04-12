cmake_minimum_required(VERSION 3.30)
project(computer_parts)

set(CMAKE_CXX_STANDARD 14)

add_executable(computer_parts main.cpp
        computer_part/computer_part.h
        computer_part_type/computer_part_type.h
        computer_part/computer_part.cpp
        computer_part_writer/computer_part_writer.h
        computer_part_reader/computer_part_reader.h
        computer_part_writer/computer_part_writer.cpp
        computer_part_type/computer_part_type.cpp
        computer_part_reader/computer_part_reader.cpp
        utilities/utilities.h
        utilities/utilities.cpp
        computer_store/computer_store.h
        string/string.h
        string/string.cpp
        array/Array.h
)
