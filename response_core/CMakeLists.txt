cmake_minimum_required(VERSION 3.15)
project(sw)

set(CMAKE_CXX_STANDARD 14)

add_executable(sw main.cpp reflex_template.c reflex_template.h r_giskard_core.c r_giskard_core.h)