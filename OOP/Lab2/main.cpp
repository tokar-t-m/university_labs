/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Lab 1.3
 * Standard: C++0x
*/
#include <iostream>
#include <IntArray.h>

using namespace std;



int main()
{
    IntArray a(5);
    IntArray v(5);
    a.print();
    int b[5] = {1,2,3,4,5};
    IntArray massive(b, 5);
    massive.print();
    cout << "Min: " << massive.min() << endl;
    cout << "Max: " << massive.max() << endl;

    IntArray massive_cpy(massive);
    massive_cpy.print();
    cout << "Size massive_cpy: " << massive_cpy.size() << endl;
    cout << "Sum: " << massive_cpy.sum() << endl;
    cout << "Multi: " << massive_cpy.multi() << endl;
    IntArray::print_objects_count();
    return 0;
}

