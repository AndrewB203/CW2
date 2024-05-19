// FlyweightPatternTest.cpp
#include "FlyweightPattern.h"
#include <gtest/gtest.h>

// Тесты для класса FlyweightFactory
class FlyweightFactoryTest : public ::testing::Test {
protected:
    FlyweightFactory factory;
};

TEST_F(FlyweightFactoryTest, GetFlyweight_CreatesNewFlyweight) {
    Flyweight* flyweight = factory.GetFlyweight("unique");
    ASSERT_NE(nullptr, flyweight);
    EXPECT_EQ("unique", flyweight->GetState());
}

TEST_F(FlyweightFactoryTest, GetFlyweight_ReturnsExistingFlyweight) {
    Flyweight* flyweight1 = factory.GetFlyweight("existing");
    Flyweight* flyweight2 = factory.GetFlyweight("existing");
    EXPECT_EQ(flyweight1, flyweight2);
}

// Тесты для класса ConcreteFlyweight
class ConcreteFlyweightTest : public ::testing::Test {
protected:
    ConcreteFlyweight flyweight;

    ConcreteFlyweightTest() : flyweight("test_state") {}
};

TEST_F(ConcreteFlyweightTest, Operation_OutputsCorrectMessage) {
    testing::internal::CaptureStdout();
    flyweight.Operation("extra_state");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "ConcreteFlyweight test_state \\ extra_state\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
