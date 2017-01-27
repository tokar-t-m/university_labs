/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Lab 1.3
 * Standard: C++0x
*/
#include <iostream>
#include <fstream>
#include <cstddef>
#include <string>
using namespace std;

int main()
{
    const char *name = "text.txt";
    fstream InOut(name, fstream::ate | fstream::in | fstream::out);
    if(!InOut){
        cerr << "Ошибка открытия файла" << endl;
        return 1;
    }
    auto end_mark = InOut.tellg();
    size_t cnt(0);
    string line;
    InOut.seekg(0, fstream::beg);
    while(InOut && InOut.tellg() != end_mark && getline(InOut, line)){
        cnt +=line.size() + 1;
        auto mark = InOut.tellg();
        InOut.seekp(0, fstream::end);
        InOut << cnt;
        if(mark != end_mark){
            InOut << " ";
        }
        InOut.seekg(mark);
    }
    InOut.seekp(0, fstream::end);
    InOut << "\n";
    cout << "Вывод в файле: " << name << endl;
    return 0;
}

