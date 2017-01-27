/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Lab5(STL_1)
 * Standard: C++0x
*/
#include <string>
using std::string;

bool isShorter(const string &s1, const string &s2){
    return s1.size() < s2.size();
}

bool GT3(const string &s){
    return s.size() > 3;
}
