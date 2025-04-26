cmake_minimum_required(VERSION 3.23)
project(game_demo3)

set(CMAKE_CXX_STANDARD 14)

add_executable(game_demo main.cpp Object.h Object.cpp Warrior.h Warrior.cpp Dragon.h Dragon.cpp Headquarter.h Headquarter.cpp Ninja.h Ninja.cpp Iceman.h Iceman.cpp Lion.h Lion.cpp Wolf.h Wolf.cpp game.h)
