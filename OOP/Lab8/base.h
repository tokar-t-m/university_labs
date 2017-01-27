/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Lab8
 * Standard: C++0x
*/
#ifndef BASE_H
#define BASE_H
#include <string>
#include <sstream>
#include <iostream>
using std::string;
using std::ostringstream;
using std::cout;
using std::endl;
class base{
    protected:
        string name;
        string last_name;
        string second_name;
        string ranks;
    public:
    base(string, string, string);
    ~base();
    virtual void rank();
};
#endif // BASE_H
