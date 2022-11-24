cmake_minimum_required(VERSION 3.23)
project(Graphics)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

find_package(SFML 2.5 COMPONENTS graphics audio network system window REQUIRED)
add_definitions(-lsfml-graphics -lsfml-window -lsfml-system -Wall -Wextra -Wpedantic)

add_executable(Graphics
        main.cpp
        MainWindow.cpp
        MainWindow.h
        Shapes.cpp
        Shapes.h
        Controls.h
        Controls.cpp
        Table.h
        Table.cpp
        Cell.h
        Cell.cpp
        stdafx.cpp
        stdafx.h

        )
target_link_libraries(Graphics sfml-graphics sfml-audio sfml-network sfml-window sfml-system)