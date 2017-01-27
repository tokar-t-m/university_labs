/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Lab 3
 * Standard: C++0x
*/
#include <iostream>
#include <new>
#include <TypeArray.h>
using namespace std;
int main()
{
    try{
    //Тут основной код!!!
        TypeArray<int> obj(10000000000);
        //TypeArray<char> ch(10);
        //cout << ch[10];
        //max adn min

        int max_min[5] = {1,2,3,4,5};
        TypeArray<int> massive(max_min, 5);
        cout << massive << "\n";
        cout << "Min: " << massive.min() << endl;
        cout << "Max: " << massive.max() << endl;

    }
    catch(out_of_range error){
        cout << error.what() << endl;
        return 1;
    }
    catch(length_error error){
        cout << error.what() << endl;
        return 2;
    }
    catch(range_error error){
        cout << error.what();
        return 3;
    }
    catch(bad_alloc){
        cout << "Ошибка выделения памяти!";
        return 4;
    }
    catch(...){
        cout << "Неизвестная ошибка!";
        return 5;
    }
    return 0;
}

