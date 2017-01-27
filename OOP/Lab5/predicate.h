/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Lab5(STL_1)
 * Standard: C++0x
*/
#ifndef PREDICATE_H
#define PREDICATE_H
#include <string>
using std::string;
bool GT3(const string &);

class LessThan{
    public:
        bool operator() (const string& s1, const string& s2){
            return s1.size() < s2.size();
        }
};

#endif // PREDICATE_H
