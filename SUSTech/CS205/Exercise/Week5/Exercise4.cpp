#include <iostream>
#include <fstream>
using namespace std;

int main() {
    cout << "Please input a string:";
    ofstream myout("f1.txt");
    string s;
    getline(cin, s);
    cout << "The contents of f1.txt : ";
    for (char ch: s) {
        if (isalpha(ch) || ch == ' ') {
            myout << ch;
            cout << ch;
        }
    }
    myout << endl;
    cout << endl;
    myout.close();
    ofstream myout2("f2.txt");
    cout << "The contents of f2.txt : ";
    for (char ch: s) {
        if (isalpha(ch)) {
            char tmp = toupper(ch);
            myout2 << tmp;
            cout << tmp;
        } else if (ch == ' ') {
            myout2 << ch;
            cout << ch;
        }
    }
    myout2 << endl;
    cout << endl;
    myout2.close();
    return 0;
}