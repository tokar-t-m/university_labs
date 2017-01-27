/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Lab 3
 * Standard: C++0x
*/
#ifndef TYPEARRAY_H
#define TYPEARRAY_H
#include <iostream>
#include <typeinfo>
#include <stdexcept>
using namespace std;
template <typename Type> class TypeArray
{
    Type *pia;
    int _size;
    //Оператор ввода
    friend istream& operator >>(istream& in, TypeArray& s){
        for(int i(0); i < s._size; ++i){
            in >> s.pia[i];
        }
        if(in){
            s = TypeArray(s._size);
        }
        return in;
    }
    //Оператор вывода
    friend ostream& operator <<(ostream& os, const TypeArray &object){
        for(int i(0); i < object._size; ++i){
            os << object.pia[i] << " ";
        }
        return os;
    }
public:
    //Конструктор по умолчанию
    TypeArray(int size = 10) {
        if(size <= 1000000){
            _size = size;
            pia = new Type[_size];
            if( typeid(*pia).name() == typeid(char).name() ){
                for(int i(0); i < _size; ++i){
                    pia[i] = '?';
                }
            }else{
                for(int i(0); i < _size; ++i){
                pia[i] = 0;
                }
            }
        }else{
            throw length_error("Массив больше 1000000 элементов!");
        }
    }

    //Конструктор копирующий
    TypeArray(const TypeArray &copy){
        _size = copy._size;
        pia = new Type[_size];
        for(int i(0); i < _size; ++i){
            pia[i] = copy.pia[i];
        }
    }

    //Инициализация встроенным массивом
    TypeArray(Type *array, int size){
        if(size <= 1000000){
            _size = size;
            pia = new Type[_size];
            for(int i(0); i < _size; ++i){
                pia[i] = array[i];
            }
        }else{
            throw length_error("Массив больше 1000000 элементов!");
        }
    }

    //Расспечатка TypeArray
    void print(){
        for(int i(0); i < _size; ++i){
            cout << pia[i] << " ";
        }
        cout << "\n";
    }

    //Размер TypeArray
    int size(){
        return _size;
    }

    //Минимум
    int min(){
        int min = pia[0];
        for(int i(0); i < _size; ++i){
            if(pia[i] < min){
                    min = pia[i];
            }
        }
        return min;
    }

    //Максимум
    int max(){
        int max = pia[0];
        for(int i(0); i < _size; ++i){
            if(pia[i] > max){
                    max = pia[i];
            }
        }
        return max;
    }

    //Синтезируемый оператор присвоения
    TypeArray& operator =(const TypeArray &rhs){

        //_size = rhs._size;
        if(_size == rhs._size){
            pia = new Type[_size];
            for(int i(0); i < _size; ++i){
                pia[i] = rhs.pia[i];
            }
            return *this;
         }else{
            throw range_error("Массивы разного размера!");
        }
    }

    //Оператор индексирования
    Type& operator [](int index){
        if(index >= 0 && index < _size){
            return pia[index];
        }else{
            throw out_of_range("Выход за пределы массива");
        }


    }

    //Оператор равенства
    bool operator ==(const TypeArray &rhs){
        if(_size != rhs._size){
            return false;
        }
        for(int i(0); i < _size; ++i){
            if(pia[i] != rhs.pia[i]){
                return false;
            }
        }
        return true;
    }

    /*
    //Оператор неравенства
    bool operator !=(const TypeArray &rhs){
        if(_size != rhs._size){
            return true;
        }else if(_size == rhs._size){
            for(int i(0); i < _size; ++i){
                if(pia[i] != rhs.pia[i]){
                    return true;
                }
            }
        }
        return false;
    }
    */

    //Оператор неравенства на базе оператора равентсва
    bool operator !=(const TypeArray &rhs){
        return !(pia == rhs.pia);
    }

    //Деструктор
    ~TypeArray(){
        delete[] pia;
    }

};
//Оператор вывода
#endif
