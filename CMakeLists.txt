cmake_minimum_required(VERSION 3.0)

project(debugmalloc)

add_compile_options(-Wall -Wextra -Werror -Wno-format)

aux_source_directory(. SRC)

add_executable(debugmalloc ${SRC})

target_include_directories(debugmalloc PRIVATE "${CMAKE_SOURCE_DIR}")
