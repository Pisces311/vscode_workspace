#include <iostream>
using namespace std;

bool is_double(string s) {
    char* end = 0;
    double val = strtod(s.c_str(), &end);
    return end != s.c_str() && *end == '\0' && val != HUGE_VAL;
}

int Fill_array(double arr[], int size) {
    string input;
    for (int i = 0; i < size; i++) {
        cout << "Enter value #" << i + 1 << ": ";
        getline(cin, input);
        if (is_double(input)) arr[i] = atof(input.c_str());
        else return i + 1;
    }
    return size;
}

void Show_array(double *arr, int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << ' ';
    cout << endl;
}

void Reverse_array(double *arr, int size) {
    if (size > 0) {
        swap(*arr, *(arr + size - 1));
        Reverse_array(arr + 1, size - 2);
    }
}

int main() {
    int sz;
    double a[20];
    cout << "Enter the size of an array:";
    cin >> sz;
    cin.get();
    int actual_size = Fill_array(a, sz);
    Show_array(a, actual_size);
    Reverse_array(a, actual_size);
    Show_array(a, actual_size);
    Reverse_array(a + 1, actual_size - 2);
    Show_array(a, actual_size);
    return 0;
}