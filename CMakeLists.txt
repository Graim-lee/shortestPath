cmake_minimum_required(VERSION 4.0)
project(shortestPath C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(shortestPath
    graphHandler.c
    graphHandler.h
    main.c
        menu.h
        menu.c)
