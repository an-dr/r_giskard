# abcmake config:
cmake_minimum_required(VERSION 3.13)
project(Core)


add_executable(${CMAKE_PROJECT_NAME} main.cpp)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
        include
        test
        )

file(GLOB_RECURSE SRC_BASECORE src/**.cpp)
file(GLOB_RECURSE SRC_TEST test/**.cpp)


target_sources(${CMAKE_PROJECT_NAME} PUBLIC
        ${SRC_BASECORE}
        ${SRC_TEST}
        )