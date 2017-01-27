/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Lab4(func_over)
 * Standard: C++0x
*/
#include <iostream>
#include <func_over.h>

using namespace std;

int main()
{
    const int SIZE(6);

    int ai[SIZE] = {1, 2, 3, 4, 5, 6};
    print_array(ai, SIZE);

    float af[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    print_array(af, SIZE);

    char ach[SIZE] = "Hello";
    print_array(ach, SIZE);

    return 0;
}

