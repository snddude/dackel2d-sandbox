cmake_minimum_required(VERSION 3.31)
project(sandbox)

add_subdirectory(vendor/c-libdackel2d)

file(GLOB_RECURSE SRC_FILES ./src/*.c)
add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ./include/)
target_link_libraries(${PROJECT_NAME} PRIVATE engine)
