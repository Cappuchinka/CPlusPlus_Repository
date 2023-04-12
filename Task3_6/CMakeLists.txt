cmake_minimum_required(VERSION 3.25)
project(Task3_6)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(lib/googletest)