cmake_minimum_required(VERSION 3.26)
project(DataStructureInC C)

set(CMAKE_C_STANDARD 11)

include_directories(line/list/arr)
include_directories(line/list/linklist/simple/head)
include_directories(line/list/linklist/simple/nohead)

add_executable(DataStructureInC
        line/list/arr/main.c
        line/list/arr/sqlist.c
        line/list/arr/sqlist.h
        line/list/linklist/simple/head/list.c
        line/list/linklist/simple/head/list.h
        line/list/linklist/simple/head/main.c
        line/list/linklist/simple/josephu/jose.c
        line/list/linklist/simple/nohead/main.c
        line/list/linklist/simple/nohead/nohead.c
        line/list/linklist/simple/nohead/nohead.h
        line/list/linklist/simple/polynomial/poly.c
        main.c)
