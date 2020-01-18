cmake_minimum_required(VERSION 3.10)

project(olibc)

set(CMAKE_C_COMPILER gcc) 

SET(GCC_COVERAGE_COMPILE_FLAGS "")
SET(GCC_COVERAGE_LINK_FLAGS    "")

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

add_library(olibc 
	src/olibc.c 
	src/container/iterator/iterator.c
	src/container/array/array.c
	src/container/list/list.c)

target_include_directories(olibc PUBLIC 
	include 
	include/container/iterator
	include/container/array
	include/container/list)

