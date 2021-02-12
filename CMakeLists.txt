cmake_minimum_required(VERSION 3.10)
project(Calculator VERSION 1.3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Calculator.out source/main.cpp source/commandLineArgs.cpp)
