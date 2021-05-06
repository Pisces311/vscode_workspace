#include "stack.h"

#include <iostream>
using namespace std;

int main() {
    Stack stk;
    for (int i = 0; i < 5; ++i) stk.push(i);
    for (int i = 0; i < stk.top; ++i) cout << stk.pitems[i] << endl;
    cout << "top: " << stk.top << endl;
    Item x;
    stk.pop(x);
    cout << x << endl;
    Stack stk2 = stk;
    stk2.pop(x);
    cout << x << endl;
    return 0;
}