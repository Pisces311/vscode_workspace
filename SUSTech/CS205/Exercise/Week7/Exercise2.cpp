#include <iostream>
using namespace std;

int int_arr[] = {1, 2, 3, 4, 5};
double double_arr[] = {1.1, 2.0, 3.0, 4.0, 5.5};

template <typename T>
T max5(T *a) {
    return *max_element(a, a + 5);
}

int main() {
    cout << "Max int = " << max5<int>(int_arr) << endl;
    cout << "Max double = " << max5<double>(double_arr) << endl;
    return 0;
}