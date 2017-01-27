/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Lab5(STL_2)
 * Standard: C++0x
*/
#include <translator.h>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    string source_name("source.txt");
    ifstream read_source(source_name.c_str(), ios::in);
    istream_iterator<string> in_it(read_source), eof;
    vector<string> source(in_it, eof);
    read_source.close();

    for_each(source.begin(), source.end(), translator);

    string trans_name("translation.txt");
    ofstream write_trans(trans_name.c_str(), ios::out);
    copy(source.begin(), source.end(), ostream_iterator<string>(write_trans, " "));
    write_trans.close();

    cout << "Результат выполнения программы выведен в файл: " << trans_name << endl;

    return 0;
}

