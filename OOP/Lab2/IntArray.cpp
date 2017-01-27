/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Lab 1.3
 * Standard: C++0x
*/
#include <IntArray.h>
using namespace std;


int IntArray::count(const int  deltha = 0){
    static int  counter = 0;
    return  counter += deltha;
}

//Количество созданных объектов IntArray
 void  IntArray::print_objects_count(){
    cout << "Количество созданных объектов IntArray: " << count() << endl;
}

//Конструктор по умолчанию
IntArray::IntArray(int size){
    _size = size;
    pia = new int[_size];
    for(int i(0); pia[i] < _size; ++i){
        pia[i] = 0;
    }
    count(1);
    //cout << "К" << endl;
}

//Конструктор копирующий
IntArray::IntArray(const IntArray &copy){
    _size = copy._size;
    pia = new int[_size];
    for(int i(0); i < _size; ++i){
        pia[i] = copy.pia[i];
    }
    count(1);
}

//Инициализация встроенным массивом
IntArray::IntArray(int *array, int size){
    _size = size;
    pia = new int[_size];
    for(int i(0); i < _size; ++i){
        pia[i] = array[i];
    }
    count(1);
}

//Расспичатать массив
void IntArray::print(){
    for(int i(0); i < _size; ++i){
        cout << pia[i] << " ";
    }
    cout << "\n";
}

//Размер массива
int IntArray::size(){
   return _size;
}

//Оператор индексации
int& IntArray::operator[](int index){
    return pia[index];
}

//Минимум
int IntArray::min(){
    int min = pia[0];
    for(int i(0); i < _size; ++i){
        if(pia[i] < min){
                min = pia[i];
        }
    }
    return min;
}

//Максимум
int IntArray::max(){
    int max = pia[0];
    for(int i(0); i < _size; ++i){
        if(pia[i] > max){
                max = pia[i];
        }
    }
    return max;
}

//Cумма
int IntArray::sum(){
    int sum(0);
    for(int i(0); i < _size; ++i){
        sum += pia[i];
    }
    return sum;
}

//Произведение
int IntArray::multi(){
    int multi(1);
    for(int i(0); i < _size; ++i){
        multi *= pia[i];
    }
    return multi;
}

//Деструктор
IntArray::~IntArray(){
    delete[] pia;
    count(-1);
    //cout << "Д" << endl;
}














