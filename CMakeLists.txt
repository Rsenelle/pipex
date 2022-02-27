cmake_minimum_required(VERSION 3.20)
project(pipex C)

set(CMAKE_C_STANDARD 99)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libft)


FILE(GLOB SRC
        "src/*.c"
        )


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall")
add_executable(pipex ${SRC})
target_link_libraries (pipex ${CMAKE_CURRENT_SOURCE_DIR}/libft/libft.a)

