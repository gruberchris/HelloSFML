cmake_minimum_required(VERSION 3.26)
project(HelloSFML)
set(CMAKE_CXX_STANDARD 20)

include(CMakeRC.cmake)
cmrc_add_resource_library(HelloSFML-Resources ALIAS HelloSFML::rc NAMESPACE HelloSFML resources/fonts/JetBrainsMono-Regular.ttf)

add_executable(HelloSFML src/main.cpp)

include_directories(/usr/local/include)

find_package(SFML 2.6 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(HelloSFML HelloSFML::rc sfml-system sfml-window sfml-graphics sfml-audio sfml-network)