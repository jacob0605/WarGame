cmake_minimum_required(VERSION 3.15)
project(WarGame2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_subdirectory(lib/googletest)
add_subdirectory(src)
add_subdirectory(tests)
