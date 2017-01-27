/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Lab 1.2
 * Standard: C++0x
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(void)
{
    const int SIZE(3);
    const char *output = "output.txt";
    int str_count(0);
    string name[SIZE] = {"file1.txt", "file2.txt", "file3.txt"};
    char *buff = new char[64];
    ifstream read;
    ofstream write(output, ios::out);
    if(write.fail()){
        cerr << "Не удалось создать выходной файл " << output << endl;
        return 1;
    }
    for(int i(0); i < SIZE; ++i){
        read.open(name[i].c_str());
        if(!read.fail()){
            while(!read.eof()){
                read.getline(buff, sizeof(buff), '\n');
                ++str_count;
            }
            read.close();
            cout << "Количество строк в файле " << name[i] << " - " << str_count << "\n" << endl;
            write << "Содержимое файла " << name[i] << endl;
            write << "Количество строк - " << str_count << endl;
            write << "Вывод файла: " << endl;
            read.open(name[i].c_str());
            while(!read.eof()){
                read.getline(buff, sizeof(buff), '\n');
                write << buff << endl;
            }
            str_count = 0;
        }else{
            cerr << "Ошибка чтения файла " << name[i] << "\n" << endl;
            write << "\nОшибка чтения файла " << name[i] << "\n" << endl;
        }
        read.close();
    }
    delete[] buff;
    write.close();
    cout << "Вывод в файле: " << output << endl;
    return 0;
}

