file(GLOB_RECURSE CHESS_ENGINE_SOURCES
    src/*.cpp
    utils/*.cpp
)

add_library(chess_engine_cpp
    ${CHESS_ENGINE_SOURCES}
)

target_include_directories(chess_engine_cpp
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/utils
)

target_compile_features(chess_engine_cpp PUBLIC cxx_std_20)

if (MSVC)
    target_compile_options(chess_engine_cpp PRIVATE /W4)
else()
    target_compile_options(chess_engine_cpp PRIVATE -Wall -Wextra -Wpedantic)
endif()
