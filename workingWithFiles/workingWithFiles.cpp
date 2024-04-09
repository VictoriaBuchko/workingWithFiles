//1) Дан текстовый файл. Необходимо создать новый файл, в который переписать 
// из исходного файла все слова, состоящие не менее чем из семи букв.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool separators(char c) {
    return (c == ' ' || c == '.' || c == ',' || c == '!' || c == '?' || c == ':');
}

bool sevenLetters(string& word) {
    return word.size() >= 7;
}

int main() {
    ifstream f1("f1.txt");
    if (!f1) {
        cerr << "Error 1" << endl;
        exit(1);
    }

    ofstream f2("f2.txt");
    if (!f2) {
        cerr << "Error 2" << endl;
        exit(1);
    }

    string line;
    while (getline(f1, line)) {
        string word = "";

        for (char c : line) {
            if (!separators(c)) {
                word += c;
            }
            else {

                if (sevenLetters(word)) {

                    f2 << word << " ";
                }
                word = "";
            }
        }
        if (!word.empty() && sevenLetters(word)) {
            f2 << word << " ";
        }
    }

 //2) Дан текстовый файл.Необходимо переписать его строки в другой файл.
 // Порядок строк во втором файле должен совпадать с порядком строк в заданном файле.
    f1.clear();
    f1.seekg(0);

    ofstream f3("f3.txt");
    if (!f3) {
        cerr << "Error 3" << endl;
        exit(1);
    }

    string words;
    while (getline(f1, words)) {
        f3 << words << endl;
    }

    return 0;
}

