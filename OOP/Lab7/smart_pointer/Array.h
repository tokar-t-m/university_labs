/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Lab7(Smart_Pointer)
 * Standard: C++0x
*/
#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <RCObject.h>
#include <RCPtr.h>
using std::cout;
using std::endl;
template<class T>
class Array{
private:
    struct ArrayValue : public RCObject{
    public:
        T *data;
        int _size;
        ArrayValue(int size);
        ArrayValue(const T* data, int size);
        ~ArrayValue();
    };
    RCPtr<ArrayValue> value;
public:
    Array(int size = 10);
    Array(const T* _data, int size);
    int size();
    T& operator[](int index);
    void show_data() const;
    int showRef() const;
};

                                    /* Реализация шаблонов методов класса Array */

/* Закрытая часть */
template<class T>
inline Array<T>::ArrayValue::ArrayValue(int size){
    _size = size;
    data = new T[_size];
}


template<class T>
inline Array<T>::ArrayValue::~ArrayValue(){
    delete[] data;
}

template<class T>
Array<T>::ArrayValue::ArrayValue(const T* _data, int size){
    data = new T[size];
    _size = size;
    for(int i = 0; i < size; ++i)
        data[i] = _data[i];
}


/* Открытая часть */
template<class T>
Array<T>::Array(int size) : value(new ArrayValue(size)){

}

template<class T>
Array<T>::Array(const T* _data, int size) : value(new ArrayValue(_data, size)){

}

template<class T>
int Array<T>::size(){
    return value->_size;
}

template<class T>
T& Array<T>::operator[](int index){
    if (index < 0 || index >= value->_size)
        cout << "Выход за пределы массива!" << endl;
    if (value->isShared()){
        value = new ArrayValue(value->data, value->_size);
    }
    value->markUnshareable();
    return value->data[index];
}

template<class T>
void Array<T>::show_data() const{
    for(int i = 0; i < value->_size; ++i)
        cout << value->data[i] << " ";
    cout << endl;
}

template<class T>
int Array<T>::showRef() const{
    return value->showRefCount();
}

#endif // ARRAY_H
