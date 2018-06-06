cmake_minimum_required(VERSION 3.9)
project(gnl_v2 C)

set(CMAKE_C_STANDARD 90)

add_executable(gnl_v2 main.c get_next_line.c get_next_line.h strings_functions.c strings_functions.h)