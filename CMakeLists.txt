cmake_minimum_required(VERSION 3.12)
project(Saper)

set(CMAKE_CXX_STANDARD 14)

set(SFML_DIR "/usr/local/opt/SFML/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Saper src/main.cpp src/Board.cpp src/Board.h src/Field.h src/Filed.cpp src/Point.cpp src/Point.h)

target_link_libraries(Saper sfml-graphics sfml-audio)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resorces/
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/textures)