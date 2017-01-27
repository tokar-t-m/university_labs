/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Lab5(STL_2)
 * Standard: C++0x
*/
#include <iterator>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class istream_pair:public pair<string, string>{
};

template<typename key, typename value>
basic_istream<key, value>& operator >>(basic_istream<key, value> &in, istream_pair &pair){
    return in >> pair.first >> pair.second;
}
typedef istream_iterator<istream_pair> ifstream_pair_iter;

void translator(string& word){
    string name_dict("dictionary.txt");
    ifstream read_dict(name_dict.c_str(), ios::in);
    map<string, string> dict((ifstream_pair_iter(read_dict)), ifstream_pair_iter());
    read_dict.close();
    char sign;
    string::size_type pos_sign;
    pos_sign = word.find_last_of(".?,!");
    if(pos_sign != string::npos){
        sign = word[pos_sign];
        if(pos_sign != EOF){
            word.erase(pos_sign);
        }
        map<string, string>::iterator map_it = dict.find(word);
        if(map_it != dict.end()){
            word = map_it->second;
            word.push_back(sign);
        }
    }else{
        map<string, string>::iterator map_it = dict.find(word);
        if(map_it != dict.end()){
            word = map_it->second;
        }
    }
}
