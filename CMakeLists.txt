cmake_minimum_required(VERSION 3.10)

project(olibc)

add_library(olibc 
	src/olibc.c 
	src/obj/obj.c 
	src/container/iterator/iterator.c
	src/container/list/list.c)

target_include_directories(olibc PUBLIC 
	include 
	include/obj
	include/container/iterator
	include/container/list)

