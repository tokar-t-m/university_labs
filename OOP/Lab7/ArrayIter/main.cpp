/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Lab7(Iterator)
 * Standard: C++0x
*/
#include <iostream>
#include <Array.h>

using namespace std;

int main()
{
    int massive[5] = {1,2,3,4,5};
    Array<int> a(massive, 5);
    Array<int> b(a);
    a.showArray();
    for(Array<int>::Iterator it = a.begin(); it != a.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}

