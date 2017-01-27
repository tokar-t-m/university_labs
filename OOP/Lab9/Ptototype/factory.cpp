/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Prototype & Factory Method  (PrototypeFactory)
 * Standard: C++0x
*/
#include <factory.h>
#include <derivatives.h>

Warrior* PrototypeFactory::createInfantrman(){
    static Infantryman prototype;
    return prototype.clone();
}

Warrior* PrototypeFactory::createArcher(){
    static Archer prototype;
    return prototype.clone();
}

Warrior* PrototypeFactory::createHorseman(){
    static Horseman prototype;
    return prototype.clone();
}
