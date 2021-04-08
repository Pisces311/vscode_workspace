#include <iostream>

#include "candybar.h"
using namespace std;

int main() {
    CandyBar *p = new CandyBar;
    cout << "Call the set function of Passing by pointer:" << endl;
    setCandyBar(p);
    cout << "Call the show function of Passing by pointer:" << endl;
    showCandyBar(p);
    CandyBar cb;
    cout << "Call the set funtion of Passing by reference:" << endl;
    setCandyBar(cb);
    cout << "Call the show function of Passing by reference:" << endl;
    showCandyBar(cb);
    return 0;
}