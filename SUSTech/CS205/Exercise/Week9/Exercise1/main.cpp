#include <iostream>

#include "golf.h"
using namespace std;

int main() {
    cout << "First version of setgolf function:" << endl;
    golf ann;
    setgolf(ann, "Ann Birdfree", 24);
    showgolf(ann);
    cout << "Second version of setgolf function:" << endl;
    golf andy;
    while (!setgolf(andy))
        ;
    showgolf(andy);
    return 0;
}