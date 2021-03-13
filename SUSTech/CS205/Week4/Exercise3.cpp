#include <iostream>
using namespace std;

int a[5];

int main() {
    cout << "Enter 5 integers:" << endl;
    for (int i = 0; i < 5; ++i) cin >> *(a + i);
    cout << "The elements of the array in reverse order are:" << endl;
    for (int i = 4; i >= 0; --i) cout << *(a + i) << ' ';
    cout << endl;
    return 0;
}