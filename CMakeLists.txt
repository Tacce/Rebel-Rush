cmake_minimum_required(VERSION 3.20)
project(TaccettiElaborato)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(C:/SFML/include)

set(SOURCE_FILES GameCharacter.cpp GameCharacter.h Definitions.h Game.cpp Game.h Gunfighter.cpp Gunfighter.h
        Swordman.cpp Swordman.h Map.cpp Map.h Projectile.cpp Projectile.h Enemy.cpp Enemy.h Sword.cpp Sword.h Obstacle.cpp Obstacle.h Menu.cpp Menu.h Shield.cpp Shield.h)

add_library(core ${SOURCE_FILES})
target_link_libraries(core sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

add_executable(TaccettiElaborato main.cpp)
target_link_libraries(TaccettiElaborato core)

