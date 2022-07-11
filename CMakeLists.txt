cmake_minimum_required(VERSION 3.20)
project(TaccettiElaborato)

set(CMAKE_CXX_STANDARD 14)

add_executable(TaccettiElaborato main.cpp GameCharacter.cpp GameCharacter.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(C:/SFML/include)
target_link_libraries(TaccettiElaborato sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

add_subdirectory(test)

set(SOURCE_FILES main.cpp GameCharacter.cpp GameCharacter.h Definitions.h)
add_library(core ${SOURCE_FILES})
target_link_libraries(TaccettiElaborato core)

