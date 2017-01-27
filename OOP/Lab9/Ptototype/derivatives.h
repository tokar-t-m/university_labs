/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Prototype & Factory Method  (PrototypeFactory)
 * Standard: C++0x
*/
#ifndef DERIVATIVES_H
#define DERIVATIVES_H
#include <base.h>
class Infantryman: public Warrior{
private:
    friend class PrototypeFactory;
    Infantryman();
public:
    Warrior* clone();
    void info();
};

class Archer: public Warrior{
private:
    friend class PrototypeFactory;
    Archer();
public:
    Warrior* clone();
    void info();
};

class Horseman: public Warrior{
private:
    friend class PrototypeFactory;
    Horseman();
public:
    Warrior* clone();
    void info();

};

#endif // DERIVATIVES_H
