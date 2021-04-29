#include <bits/stdc++.h>
using namespace std;

class Number {
   private:
    int val;

   public:
    Number() : val(0) {}
    Number(int val) : val(val) {}
    friend ostream &operator<<(ostream &os, Number a) { return os << a.val; }
    Number operator++() { return Number(++val); }
    Number operator++(int) {
        int tmp = val;
        val++;
        return tmp;
    }
    Number operator--() { return Number(--val); }
    Number operator--(int) {
        int tmp = val;
        val--;
        return tmp;
    }
};

int main() {
    Number n1(20);
    Number n2 = n1++;

    cout << "n1 = " << n1 << endl;
    cout << "n2 = " << n2 << endl;

    Number n3 = n2--;
    cout << "n2 = " << n2 << endl;
    cout << "n3 = " << n3 << endl;

    Number n4 = ++n3;
    cout << "n3 = " << n3 << endl;
    cout << "n4 = " << n4 << endl;

    Number n5 = --n4;
    cout << "n4 = " << n4 << endl;
    cout << "n5 = " << n5 << endl;

    return 0;
}