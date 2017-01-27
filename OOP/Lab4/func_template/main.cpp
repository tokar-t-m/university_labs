/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Lab4(func_template)
 * Standard: C++0x
*/
#include <iostream>
#include <func_template.h>
using std::cout;
using std::endl;
int main()
{
    /*
    const int SIZE(6);

    int ai[SIZE] = {1, 2, 3, 4, 5, 6};
    print_array(ai);
    cout << "\n";

}
    float af[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    print_array(af);
    cout << "\n";

    char ach[SIZE] = "Hello";
    print_array(ach);
    cout << "\n";
    */

    int i = max(10, 20);
    cout << "Max: " << i << endl;
    char const *p = max("worldsss", "worldss");
    cout << "Max_str: " << p << endl;


    return 0;
}

