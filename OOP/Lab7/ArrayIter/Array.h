/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Lab7(Iterator)
 * Standard: C++0x
*/
#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

template<class T>
class Array{
private:
    T *pta;
    int _size;
public:
    Array(int size = 10);
    Array(T *pta, int size);
    Array(const Array &copy);
    void showArray();
    ~Array();
    class Iterator{
    private:
        const Array &ptr;
        int index;
    public:
        Iterator(const Array &obj) : ptr(obj), index(0){
        }
        Iterator(const Array &obj, bool) : ptr(obj), index(obj._size){
        }
        T current(){
            return ptr.pta[index];
        }
        T operator*(){
            return current();
        }
        T operator++(){
            return ptr.pta[++index];
        }
        bool operator!=(const Iterator &rhs){
            return index != rhs.index;
        }
        friend ostream& operator<<(ostream &os, const Iterator &rhs){
            return os << *rhs;
        }

        bool operator==(const Iterator &rhs){
            return index = rhs.index;
        }

    };
    Iterator begin(){
        return Iterator(*this);
    }
    Iterator end(){
        return Iterator(*this, true);
    }
};


                                                /* Реализация методов */
template<class T>
inline Array<T>::Array(int size){
    _size = size;
    pta = new T[_size];
}

template<class T>
inline Array<T>::Array(T *array, int size){
    _size = size;
    pta = new T[_size];
    for(int i(0); i < _size; ++i)
        pta[i] = array[i];

}

template<class T>
inline Array<T>::Array(const Array &copy){
    _size = copy._size;
    pta = new T[_size];
    for(int i(0); i < _size; ++i)
        pta[i] = copy.pta[i];
}

template<class T>
inline void Array<T>::showArray(){
    for(int i(0); i < _size; ++i)
        cout << pta[i] << " ";
    cout << endl;
}

template<class T>
inline Array<T>::~Array(){
    delete[] pta;
}

#endif // ARRAY_H
