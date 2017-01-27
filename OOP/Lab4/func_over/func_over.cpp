/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Lab4(func_over)
 * Standard: C++0x
*/
#include <iostream>
using std::cout;
using std::endl;

void print_array(int* array, const int size){
    for(int i(0); i < size; ++i){
        cout << array[i] << " ";
    }
    cout << " - вызвана функция void print_array(int*, int);";
    cout << "\n";
}

void print_array(float* array, const int size){
    for(int i(0); i < size; ++i){
        cout << array[i] << " ";
    }
    cout << " - вызвана функция void print_array(float*, int);";
    cout << "\n";
}

void print_array(char* array, const int size){
    for(int i(0); i < size; ++i){
        cout << array[i];
    }
    cout << " - вызвана функция void print_array(char*, int);";
    cout << "\n";
}




