cmake_minimum_required(VERSION 3.15)
project(MUL_my_rpg_2019 C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

file (GLOB lib_dir
        "src/*.c")

add_executable(MUL_my_rpg_2019 ${lib_dir})

target_link_libraries(MUL_my_rpg_2019 csfml-window csfml-graphics csfml-audio
        csfml-system m)