cmake_minimum_required(VERSION 3.5)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
LINK_LIBRARIES(sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(C:/SFML/include)

set(SOURCE_TEST_FILES runAllTests.cpp SwordmanTest.cpp GunfighterTest.cpp GameTest.cpp ProjectileInstersectionFixture.cpp SwordIntersectionFixture.cpp)
add_executable(runAllTests ${SOURCE_TEST_FILES})
target_link_libraries(runAllTests gtest gtest_main)

