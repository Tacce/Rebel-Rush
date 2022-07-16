#include "gtest/gtest.h"
#include <SFML/Graphics.hpp>
#include "../GameCharacter.cpp"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}