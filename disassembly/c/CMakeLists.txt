cmake_minimum_required(VERSION 3.10)
project(ctest)
add_executable(main.out main.c)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g")
