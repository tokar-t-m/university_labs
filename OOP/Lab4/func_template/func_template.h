/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Lab4(func_template)
 * Standard: C++0x
*/
#ifndef FUNC_TEMPLATE_H
#define FUNC_TEMPLATE_H
#include <iostream>
#include <cstring>
using std::cout;
/*
//Шаблон функции с параметрами
template<typename T, const int SIZE>
void print_array(T (&array)[SIZE]){
    const int VALUE = SIZE;
    for(int i(0); i < VALUE; ++i){
        cout << array[i] << " ";
    }
}
//Специализированный шаблон функции
//template<> print_array
*/


template<typename T>
T max(T t1, T t2){
    return ( t1 < t2 ? t1 : t2);
}

typedef const char *PCC;
template<> PCC max<PCC>(PCC t1, PCC t2){
    return (strcmp(t1, t2) > 0 ? t1 : t2);
}

#endif // FUNC_TEMPLATE_H
