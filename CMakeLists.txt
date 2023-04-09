cmake_minimum_required(VERSION 3.23)
project(lab14 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab14 main.c libs/dataStructures/vector/vector.c libs/dataStructures/vector/vector.h)
