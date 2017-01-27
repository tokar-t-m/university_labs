/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Lab 1.1
 * Standard: C++0x
*/
#include <iostream>
using namespace std;
istream &input(istream &);

int main()
{
    input(cin);
    return 0;
}
istream &input(istream &in){
    char buff[64];
    cout << "Введите данные: " << endl;
    while( in.get(buff, 64) && !in.eof() );
    cout << "\nВывод данных:" << endl;
    for(int i(0); buff[i] != '\0'; i++)
        cout << buff[i];
    cout << "\n\nCостояние флагов после ввода данных:" << endl;
    cout << "Флаг eof(): " << in.eof() << endl;
    cout << "Флаг bad(): " << in.bad() << endl;
    cout << "Флаг fail(): " << in.fail() << endl;
    cout << "Флаг good(): " << in.good() << endl;
    in.clear();
    cout << "\nCостояние флагов после очистки:" << endl;
    cout << "Флаг eof(): " << in.eof() << endl;
    cout << "Флаг bad(): " << in.bad() << endl;
    cout << "Флаг fail(): " << in.fail() << endl;
    cout << "Флаг good(): " << in.good() << endl;
    return in;
}
