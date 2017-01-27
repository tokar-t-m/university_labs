/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Prototype & Factory Method  (PrototypeFactory)
 * Standard: C++0x
*/
#include <iostream>
#include <vector>
#include <factory.h>

using namespace std;

int main()
{
    PrototypeFactory factory;
    vector<Warrior*> v;
    v.push_back(factory.createInfantrman());
    v.push_back(factory.createArcher());
    v.push_back(factory.createHorseman());

    for(size_t i = 0; i < v.size(); ++i){
        v[i]->info();
    }

    return 0;
}

