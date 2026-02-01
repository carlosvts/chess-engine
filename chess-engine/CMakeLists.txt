cmake_minimum_required(VERSION 3.16)

project(
    chess_engine
    VERSION 0.1.0
    LANGUAGES CXX
)

# C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Sub dir with the source files
add_subdirectory(cpp)
