#include <gtest/gtest.h>
#include <FlyweightPattern.h>

TEST(check, FlyweightPatternTest)
{
	FlyweightFactory* fc =new FlyweightFactory();
	Flyweight* fw1=fc->GetFlyweight("hello");
	Flyweight* fw2=fc->GetFlyweight("hello");
	EXPECT_EQ(fw1, fw2); 
}

TEST(check, FlyweightCreationTest)
{
	FlyweightFactory* fc= new FlyweightFactory();
	Flyweight *fw1 = fc->GetFlyweight("hello");
    	Flyweight *fw2 = fc->GetFlyweight("world");
    	Flyweight *fw3 = fc->GetFlyweight("hello");
    	EXPECT_EQ(fc->count(), 2);
}

TEST(check, FLyweightStateTest)
{
	FlyweightFactory* fc= new FlyweightFactory();
	Flyweight *fw1 = fc->GetFlyweight("hello");
	EXPECT_STREQ(fw1->GetState(), "hello");

}
