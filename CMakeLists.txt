cmake_minimum_required(VERSION 3.10)
project(TD2D)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set source files location
file(GLOB SRC_FILES src/main.cpp
                    src/map.cpp
)

# Find Raylib
find_package(raylib REQUIRED)
include_directories(src/)

# Add executable
add_executable(TD2D ${SRC_FILES})

# Link Raylib
target_link_libraries(TD2D raylib)

# Set binary output directory
set_target_properties(TD2D PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

