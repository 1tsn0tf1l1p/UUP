cmake_minimum_required(VERSION 3.27)
project(prodavnica2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)

add_executable(prodavnica2
        .idea/.gitignore
        .idea/discord.xml
        .idea/modules.xml
        .idea/prodavnica2.iml
        main.c
        main.exe
        prodavnice.txt)
