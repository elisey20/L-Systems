cmake_minimum_required(VERSION 3.19)
project(sfml_test)

set(CMAKE_CXX_STANDARD 20)

set(SFML_DIR "/home/elisey/CLionProjects/sfml-test/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML COMPONENTS graphics audio REQUIRED)

add_executable(main main.cpp Turtle.cpp)

target_link_libraries(main PRIVATE sfml-graphics PRIVATE sfml-audio)