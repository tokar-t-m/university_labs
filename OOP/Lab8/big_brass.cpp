/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Lab8
 * Standard: C++0x
*/
#include <big_brass.h>
big_brass::big_brass(const string last_name, const string name, const string second_name) : base(name, last_name, second_name){
    this->ranks = "состоит в высшим офицерском составе";
}
void big_brass::rank(){
    cout << this->last_name << " " << this->name << " " << this->second_name << " - " << this->ranks << endl;
}

