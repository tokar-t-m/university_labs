/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Lab5(STL_1)
 * Standard: C++0x
*/
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
#include <predicate.h>

using namespace std;

int main()
{
    const char *name_file1 = "file1.txt"; //Задаёт имя файля для перечня слов в set'e
    ifstream read1(name_file1, ios::in); //читает файл с именем содержащийся в переменной name_file1
    string buff; //Переменная в которую записывается по одному слову
    set<string> sset; //контейнер, который содержит набор слов из файла с именем содержащийся в переменной name_file1
    //Проверка на существование файла
    if(!read1){
        throw runtime_error("no file");
    }
    //Добавление в контейнер set
    while(!read1.eof()){ //Читает файл пока не конец файла
        read1 >> buff; //перенаправляет поток из файла во временную переменную buff
        //buff += '\0';
        sset.insert(buff); //Вставляет по одному элементу в контейнер set из временной переменной buff
    }
    read1.close(); //Закрытие файла после чтения

    const char *name_file2 = "file2.txt"; //Задаёт имя файля для перечня слов в list'e
    //ifstream InOut2(name_file2, ios::in); //читает файл с именем содержащийся в переменной name_file2
    fstream InOut2(name_file2, fstream::in | fstream::out | fstream::app);
    vector<string> svec; //контейнер, который содержит набор слов из файла с именем содержащийся в переменной name_file2
    /*
     *                                      Обоснования выбора контейнера
     *
     * Можно выбрать любой контейнер так как:
     *
     * vector - обеспечивает быстрый поиск удаляемого элемента, но само удаление происходит медленее, потому что
     * придётся сдвигать элементы контейнера.
     *
     * list - обеспечивает быстрое удаление элемента, но долгий поиск удаляемого элемента, потому что
     * надо пройти по всем элементам контейнера.
     *
     */
    //Проверка на существование файла
    if(!InOut2){
        throw runtime_error("no file");
    }
    /*
    //обавляем в контейнер svec, при этом исключаем слова содержащийся в контейнере sset
    while(!InOut2.eof()){ //Читает файл пока не конец файла
        InOut2 >> buff; //перенаправляет поток из файла во временную переменную buff
        //Удаляем знак препинания
        for(unsigned int i(0); i < buff.size(); ++i){
            if(buff[i] == ',')
                buff[i] = '\0';
        }
        if(sset.count(buff) == 0)
            svec.push_back(buff);
    }
    */
    string::size_type k;
    while(!InOut2.eof()){
        InOut2 >> buff;
        k = buff.find_last_of(",.!?");
        if(k != -1)
            buff.erase(k);
        if(sset.count(buff) == 0)
            svec.push_back(buff);
    }
    //InOut2.close();

    set<string> count_set(svec.begin(), svec.end());
    int i;
    set<string>::iterator set_it;
    const char *name_file3 = "file3.txt";
    ofstream write3(name_file3, ios::out);
    if(write3.fail()){
        throw runtime_error("not create file");
    }
    for(set_it = count_set.begin(); set_it != count_set.end(); ++set_it){
        i = count(svec.begin(), svec.end(), *set_it);
        //cout << "Слово: " << *set_it << " встречается - " << i << " раз" << endl;
        if(i > 1){
            write3 << "Слово: " << *set_it << " встречается - " << i << " раз" << endl;
        }
    }
    write3.close();
    cout << "Статистика встречаемости слов выведена в файл: " << name_file3 << endl;

    sort(svec.begin(), svec.end()); //Лексикографическая сортировка
    vector<string>::iterator end_unique = unique(svec.begin(), svec.end()); //Перенос дублирующих слов в конец вектора
    svec.erase(end_unique, svec.end()); //Удаление дублирующих слов из вектора
    stable_sort(svec.begin(), svec.end(), LessThan()); //Сортировка по длине с помощью объукта функции
    vector<string>::size_type wc = count_if(svec.begin(), svec.end(), GT3);
    //cout << "Количество: " << wc << endl;

    InOut2.seekg(0, ios::end);
    InOut2 << "\nРезультат сортировки:" << endl;
    vector<string>::iterator vec_it;
    for(vec_it = svec.begin() + (svec.size() - wc); vec_it != svec.end(); ++vec_it){
        //cout << *vec_it << endl;
        InOut2 << *vec_it << endl;
    }
    InOut2.close();

    cout << "Результат сортировки выведен в файл: " << name_file2 << endl;

    return 0;
}

