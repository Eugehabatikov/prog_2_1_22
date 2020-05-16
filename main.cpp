#include <iostream>
#include <fstream>
#include <map>
using namespace std;

/**
  in this class implemented word, save information of  count and ending.
 **/

class Sentence {
public:

    public: void print(string line) {
        map<string, int> stringStor;
        map<string, int> result;
        string delim = " ";   // строка или символ разделитель
        size_t pos = 0;
        size_t base_str_size = line.size();
        size_t delim_size = delim.size();
        string temp; // cлово
        while (pos < base_str_size) {
            temp = temp.assign(line, pos, line.find(delim, pos) - pos);
            if (temp.size() > 0)  // проверка на пустую строку при необходимости
                stringStor.insert ( pair<string ,int>(temp,0) );
            pos += temp.size() + delim_size;

        }
        //clear(stringStor)
        //тут определим окончание и количество таких же слов (попутно удаляя дублеры)
        for (int i = 0; i < stringStor.size(); i++)
        {

        }

        //тут выводим по такому принципу cout << mapValueString << "(" << mapValueInt << ")" << " "

    }
//string[] clear (string stringStor[])
//{}


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
