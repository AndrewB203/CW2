#include "FlyweightPattern.h"



int main() {
    FlyweightFactory *fc = new FlyweightFactory();
    Flyweight *fw1 = fc->GetFlyweight("hello");
    Flyweight *fw2 = fc->GetFlyweight("world");
    Flyweight *fw3 = fc->GetFlyweight("hello");
	
	
    delete fw1;
    delete fw2;
    //delete fw3;
    delete fc;

    return 0;
}




