#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    while (true) {
        cout << "Enter an integer number:";
        int x;
        cin >> x;
        sum += x;
        cout << "The cumulative sum of the entries to date is :" << sum << endl;
        if (!x)
            break;
    }
    return 0;
}