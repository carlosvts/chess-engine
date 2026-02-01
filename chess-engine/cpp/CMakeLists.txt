# Fetching files from source and utils
file(GLOB_RECURSE CHESS_ENGINE_SOURCES
    src/*.cpp
    utils/*.cpp
)
# Including headers
file(GLOB_RECURSE CHESS_ENGINE_HEADERS
    include/**/*.hpp # ** makes goes recursevly through the directory
    utils/*.hpp
)

add_library(chess_engine_cpp
    ${CHESS_ENGINE_SOURCES}
    ${CHESS_ENGINE_HEADERS}
)

target_include_directories(chess_engine_cpp
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/utils
)

target_compile_features(chess_engine_cpp PUBLIC cxx_std_20)

# Warnings (bons pra engine)
# We can disable in future when going to production, just removing Wall Wextra and other debug flags
if (MSVC)
    target_compile_options(chess_engine_cpp PRIVATE /W4)
else()
    target_compile_options(chess_engine_cpp PRIVATE -Wall -Wextra -Wpedantic)
endif()
