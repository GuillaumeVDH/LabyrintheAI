cmake_minimum_required(VERSION 3.1)
project(Labyrinthe)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -static")

set(SOURCE_FILES main.cpp)
add_executable(Labyrinthe ${SOURCE_FILES} handlers/MapHandler.cpp handlers/MapHandler.h model/Map.cpp model/Map.h handlers/FileHandler.cpp handlers/FileHandler.h singleton/Singleton.h Labyrinthe.cpp Labyrinthe.h Constants.h model/Coordinates.cpp model/Coordinates.h)