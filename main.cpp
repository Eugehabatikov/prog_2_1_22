#include <fstream>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>


using namespace std;

/**
  in this class implemented word, save information of quantity and ending.
 **/

class Sentence {

public:
    Sentence(string line) {
        print(line);
    }

    map<string, int> stringStor;

    void print(string line) {

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
            for (int i = 0; i < sizeof(temp) - 1; i++) {
                if (temp[i] > 'A' && temp[i] < 'Z') temp[i] += 'z' - 'Z';
            }
            //clear not alphabet sumbols
            for (int i = 0; i < temp.size(); i++)//АТТЕНШЕН, СУКА
                if (isalpha(temp[i]) > 0)
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
        printer();
    }


    void printer() {
        pair<string, int> max;
        pair<string, int> otherPair;
        const char *otherC;
        const char *maxC;
        map<string, int> result;//in this plase i save inform about result my sentence
        for (auto &item : stringStor) {
            max.first = item.first;
            max.second = max.second;
            maxC = &item.first[item.first.size() - 1];
            if (result.count(max.first) == 0) {
                for (auto &stor : stringStor) {
                    otherPair.second = stor.second;
                    otherPair.first = stor.first;
                    otherC = &stor.first[stor.first.size() - 1];
                    if (result.count(otherPair.first) == 0 && max.first != otherPair.first &&
                        strcmp(maxC, otherC) > 0) {
                        result.insert(max);
                    } else if (result.count(otherPair.first) == 0 && max.first != otherPair.first &&
                               strcmp(maxC, otherC) < 0) {
                        max = otherPair;
                    }
                }
            }
        }
        for (auto &item : result) {
            cout << ",";
            cout << item.first << "(" << item.second << ")";
        }
        cout << "total number of distinguished words = " << stringStor.size() << result.size();

    }


};

int main() {
    string nameOfFile;//for check to ready program
    cout << "Hello, welcome to a board. This program can make you text to the principle: \n"
            "For all word in one sentence i take all unique word,\n"
            "count all duplicate this word in sentence, and sort descending on quantity duplicate \n"
            "and last letter, on enter the sentence i print inform of count all unique word in sentence\n"
            "Simple sentence: to be, or not to be, that is the question \n"
            "result of program: be(2), to(2), the(1), question(1), or(1), is(1), not(1), that(1).(total unique word - 8)\n"
            "when you want start using programm print path to you file where i can take you text\n";
    cin >> nameOfFile;
        string line;
        ifstream in(nameOfFile);
        if (in.is_open())
        {
            while (getline(in, line))
            {
                new Sentence(line);
            }
        }
        in.close();
        return 0;
    }


