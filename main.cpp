#include <fstream>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
/**
  in this class implemented word, save information of  count and ending.
 **/

class Sentence {

public:
    void print(string line) {
        map<string, int> stringStor;
        map<string, int> result;
        string delim = " ";
        size_t pos = 0;
        size_t base_str_size = line.size();
        size_t delim_size = delim.size();
        string temp;
        string clearTemp;//for word without other sumbols

        while (pos < base_str_size) {
            temp = temp.assign(line, pos, line.find(delim, pos) - pos);
            //change to lowerCase
            for(int i=0; i<sizeof(temp)-1; i++)
            {
                if(temp[i]>'A' && temp[i]<'Z') temp[i]+='z'-'Z';
            }
            //clear not alphabet sumbols
            for(int i=0;i<temp.size();i++)//АТТЕНШЕН, СУКА
                if(isalpha(temp[i]) > 0)
                    clearTemp.insert(i, string(reinterpret_cast<const char *>(temp[i])));//ой хз, брат

            if (temp.size() > 0)
                if (stringStor.count(temp) > 0)//if i have this word in my map i increase counter of this word
                {
                    stringStor.find(temp)->second++;
                }
                    //if i didn't have this word i made new element on map
                else stringStor.insert(pair<string, int>(temp, 1));
            pos += temp.size() + delim_size;
        }

        for(auto& item : stringStor)
        {
            cout << item.first << " : " << item.second << endl; //Вывод ключей и значений
        }

    }
 void printer()
 {//тут выводим по такому принципу cout << mapValueString << "(" << mapValueInt << ")" << " "

     cout << "total number of distinguished words = " ;//<< размер переданного массива
 }
};

int main() {
    string nameOfFile;
    cout << "Hello, welcome to a board. ";//дописать приветствие
    cin >> nameOfFile;
    string line; //
    ifstream in(nameOfFile);
    if (in.is_open()) {
        while (getline(in, line)) {
            Sentence.print(line);
        }
    }
    in.close();
    return 0;
}
