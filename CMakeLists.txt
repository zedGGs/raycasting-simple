cmake_minimum_required(VERSION 3.25)
project(raycaster)

set(CMAKE_C_STANDARD 11)

# Find SDL2
find_package(SDL2 REQUIRED COMPONENTS SDL2)

# Add .c files into executable
file (GLOB_RECURSE SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.c"
                             "${CMAKE_SOURCE_DIR}/src//*/**/*.c"
                             )

add_executable (raycaster ${SRC_FILES})

# Create pre-compiled header
file (GLOB_RECURSE UTIL_HEADERS "${CMAKE_SOURCE_DIR}/src//Utilities/*.h")
##set (COMMON_HEADERS "${CMAKE_SOURCE_DIR}/src/Utilities/COMMON_HEADERS.h")
target_precompile_headers (raycaster PRIVATE ${COMMON_HEADERS} ${UTIL_HEADERS})

# Link SDL2
target_link_libraries(raycaster PRIVATE SDL2::SDL2)