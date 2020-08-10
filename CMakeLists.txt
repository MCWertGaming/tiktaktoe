cmake_minimum_required(VERSION 3.17)
project(tiktaktoe)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_executable(tiktaktoe ${PROJECT_SOURCE_DIR}/src/main.cpp)