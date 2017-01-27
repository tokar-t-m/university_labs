/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Lab8
 * Standard: C++0x
*/
#include <senior_officers.h>
senior_officers::senior_officers(const string last_name, const string name, const string second_name) : base(name, last_name, second_name){
    this->ranks = "состоит в старшим офицерском составе";
}
void senior_officers::rank(){
    cout << this->last_name << " " << this->name << " " << this->second_name << " - " << this->ranks << endl;
}
