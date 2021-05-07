cmake_minimum_required(VERSION 3.15)
project(data_final)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(data_final
        bst.c
        bst.h
        evaluation.c
        evaluation.h
        heap.c
        heap.h
        main.c
        src.txt
        stack.c
        stack.h
        varstruct.h)
