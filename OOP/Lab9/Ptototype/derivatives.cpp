/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Prototype & Factory Method  (PrototypeFactory)
 * Standard: C++0x
*/
#include <derivatives.h>
#include <iostream>
using std::cout;
using std::endl;

//Infantryman - пехотинец
Warrior* Infantryman::clone(){
    return new Infantryman( *this);
}

void Infantryman::info(){
    cout << "Infantryman" << endl;
}

Infantryman::Infantryman(){

}

//Archer - стрелок
Warrior* Archer::clone(){
    return new Archer(*this);
}

void Archer::info(){
    cout << "Archer" << endl;
}

Archer::Archer(){

}

//Horseman - всадник
Warrior* Horseman::clone(){
    return new Horseman(*this);
}

void Horseman::info(){
    cout << "Horsmen" << endl;
}

Horseman::Horseman(){

}
