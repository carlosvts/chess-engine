# ===============================
# Fetch pybind11
# ===============================
include(FetchContent)

FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11.git
    GIT_TAG v2.12.0
)

FetchContent_MakeAvailable(pybind11)

# ===============================
# Engine core (C++ only)
# ===============================
file(GLOB_RECURSE CHESS_ENGINE_SOURCES
    src/*.cpp
    utils/*.cpp
)

# Remove bindings from core
list(REMOVE_ITEM CHESS_ENGINE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/bindings.cpp
)

add_library(chess_engine_core
    ${CHESS_ENGINE_SOURCES}
)

target_include_directories(chess_engine_core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/utils
)

target_compile_features(chess_engine_core PUBLIC cxx_std_20)

if (MSVC)
    target_compile_options(chess_engine_core PRIVATE /W4)
else()
    target_compile_options(chess_engine_core PRIVATE -Wall -Wextra -Wpedantic)
endif()

# ===============================
# Python bindings (pybind11)
# ===============================
pybind11_add_module(chess_engine_cpp
    src/bindings.cpp
)

target_link_libraries(chess_engine_cpp
    PRIVATE chess_engine_core
)
