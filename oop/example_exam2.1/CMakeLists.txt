cmake_minimum_required(VERSION 3.30)
project(example_exam2_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(example_exam2_1 main.cpp
        DynamicArray/DynamicArray.cpp
        DynamicArray/DynamicArray.h
        Player/Player.cpp
        Player/Player.h
        Position/Position.h
        Warrior/Warrior.cpp
        Warrior/Warrior.h
        Mage/Mage.cpp
        Mage/Mage.h
        PlayerCollection/PlayerCollection.cpp
        PlayerCollection/PlayerCollection.h
)
