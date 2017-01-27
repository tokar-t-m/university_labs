/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Lab 2
 * Standard: C++0x
*/
#ifndef INT_ARRAY_H
#define INT_ARRAY_H
#include <iostream>
class IntArray
{
    static int count(const int);
    int _size;
    int *pia;
public:
    int cnt = 0;
    IntArray(int);
    IntArray(const IntArray&);
    IntArray(int*, int);
    void print();
    int size();
    int& operator[](int);
    int min();
    int max();
    int sum();
    int multi();
    ~IntArray();
    static void  print_objects_count();
};
#endif
