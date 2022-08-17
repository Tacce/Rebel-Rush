cmake_minimum_required(VERSION 3.5)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_TEST_FILES runAllTests.cpp SwordmanTest.cpp GunfighterTest.cpp GameTest.cpp ProjectileInstersectionFixture.cpp SwordIntersectionFixture.cpp ObstacleIntersectionFixture.cpp)
add_executable(runAllTests ${SOURCE_TEST_FILES})
target_link_libraries(runAllTests core gtest gtest_main)

