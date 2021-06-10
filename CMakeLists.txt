cmake_minimum_required(VERSION 3.10)

project(ZenithDoom C)

link_directories(${CMAKE_SOURCE_DIR}/lib)
include_directories(${CMAKE_SOURCE_DIR}/include/SDL2)

file(GLOB SOURCE_FILES
	${CMAKE_SOURCE_DIR}/src/*.c
	${CMAKE_SOURCE_DIR}/src/*.h)

add_executable(ZenithDoom ${SOURCE_FILES})
target_link_libraries(ZenithDoom SDL2 SDL2main)