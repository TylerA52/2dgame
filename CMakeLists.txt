cmake_minimum_required(VERSION 3.10)

project(2dgame)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Recursively gather all .cpp files in the src directory
file(GLOB_RECURSE SOURCES
    "src/main.cpp"
    "src/**/*.cpp"
)

# Find SDL2 package
find_package(SDL2 REQUIRED)

# Add the src directory to the include path
include_directories(${CMAKE_SOURCE_DIR}/src)

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Include SDL2 directories
include_directories(${SDL2_INCLUDE_DIRS})

# Link SDL2 libraries
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})


