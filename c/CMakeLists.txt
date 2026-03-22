cmake_minimum_required(VERSION 4.0.0)
project(conways_game_of_life)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)
find_package(SDL3 REQUIRED)

include_directories(include)

add_executable(${PROJECT_NAME}
    src/main.c
    src/ui.c)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    SDL3::SDL3)
