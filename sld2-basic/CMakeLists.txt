cmake_minimum_required(VERSION 3.29)
project(sld2_basic C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

set(SDL2_PATH "C:/COMPUTER-GRAPHICS/SDL2-2.30.7/x86_64-w64-mingw32")
find_package(SDL2 REQUIRED)
include_directories("C:/COMPUTER-GRAPHICS/SDL2-2.30.7/x86_64-w64-mingw32/include/SDL2")


add_executable(sld2_basic main.c)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})