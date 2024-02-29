cmake_minimum_required(VERSION 3.27)
project(SystemProgramming)

set(CMAKE_CXX_STANDARD 23 -v)



add_executable(SystemProgramming main.cpp
        Lab1/cpC_files.h
        Lab1/Lab1.cpp
        Lab2/console_utils.h
        Lab2/console_utils.cpp
        Lab3/error_utils.h
        Lab3/error_utils.cpp
        Lab4/write_utils.h
        Lab4/write_utils.cpp
        Lab5/ascii_conver_utils.h
        Lab5/ascii_conver_utils.cpp
        Lab6/file_systems_utils.h
        Lab6/file_systems_utils.cpp
        Lab7/text_utils.h
        Lab7/text_utils.cpp
)
