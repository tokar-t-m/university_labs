/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Prototype & Factory Method  (PrototypeFactory)
 * Standard: C++0x
*/
#ifndef BASE_H
#define BASE_H
class Warrior{
public:
    virtual Warrior* clone() = 0;
    virtual void info() = 0;
    virtual ~Warrior();
};
#endif // BASE_H
