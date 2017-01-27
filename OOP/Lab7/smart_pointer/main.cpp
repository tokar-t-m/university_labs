/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Lab7(Smart_Pointer)
 * Standard: C++0x
*/
#include <iostream>
#include <Array.h>

using namespace std;

int main()
{
    int mass[5] = {1,2,3,4,5};
    Array<int> obj(mass, 5);

    Array<int> a(obj);
    Array<int> b(obj);
    Array<int> c(obj);

    cout << "После инициализации объектов: " << obj.showRef() << endl;

    int value = 10;
    a[0] = value;
    cout << "После изменения одного из объектов: " << obj.showRef() << endl;
    a = obj;
    cout << "После возвращения объекта в исходное значение: " << obj.showRef() << endl;

    return 0;
}

