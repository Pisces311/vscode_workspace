#include <iostream>
using namespace std;

template <typename T>
T Max(T one, T two);

int main() {
    cout << "The max of two integers " << 5 << " and " << 3 << " is "
         << Max(5, 3) << endl;
    cout << "The max of two doubles " << 3.5 << " and " << 10.3 << " is "
         << Max(3.5, 10.3) << endl;
    cout << "The max of two strings Hello and World is "
         << Max("Hello", "World") << endl;

    return 0;
}

template <typename T>
T Max(T one, T two) {
    T biggest;
    if (one < two)
        biggest = two;
    else
        biggest = one;

    return biggest;
}