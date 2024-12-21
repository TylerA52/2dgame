cmake_minimum_required(VERSION 3.10)

project(2dgame)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# recursively get .cpp files in src dir
file(GLOB_RECURSE SOURCES
    "src/main.cpp"
    "src/**/*.cpp"
)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/src)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} SDL2_image::SDL2_image)


