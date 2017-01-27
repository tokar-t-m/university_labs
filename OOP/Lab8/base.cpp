/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Lab8
 * Standard: C++0x
*/
#include <base.h>
base::base(string last_name, string name, string second_name){
    this->name = name;
    this->last_name = last_name;
    this->second_name = second_name;
    this->ranks = "не состоит в офицерском составе";
}
base::~base(){
}
void base::rank(){
    cout << this->last_name << " " << this->name << " " << this->second_name << " - " << this->ranks << endl;
}
