cmake_minimum_required(VERSION 3.15)

project(bouncing-ball
    VERSION 0.1
    LANGUAGES C
)

include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG        5.0
)

FetchContent_MakeAvailable(raylib)

add_executable(bouncing-ball main.c)

target_link_libraries(bouncing-ball raylib)
