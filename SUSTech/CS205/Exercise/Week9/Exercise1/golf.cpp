#include "golf.h"

#include <string.h>

#include <iostream>
using namespace std;

void setgolf(golf& g, const char* name, int hc) {
    strcpy(g.fullname, name);
    g.handicap = hc;
}

int setgolf(golf& g) {
    cout << "Enter the fullname:";
    cin.getline(g.fullname, Len);
    cout << "Enter the handicap:";
    cin >> g.handicap;
    cin.get();
    return strlen(g.fullname) ? 1 : 0;
}

void handicap(golf& g, int hc) { g.handicap = hc; }

void showgolf(const golf& g) {
    cout << "The name of golf is " << g.fullname << " and its handicap is "
         << g.handicap << endl;
}