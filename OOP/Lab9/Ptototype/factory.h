/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Prototype & Factory Method  (PrototypeFactory)
 * Standard: C++0x
*/
#ifndef FACTORY_H
#define FACTORY_H
#include <base.h>
class PrototypeFactory{
public:
    Warrior* createInfantrman();
    Warrior* createArcher();
    Warrior* createHorseman();
};
#endif // FACTORY_H
