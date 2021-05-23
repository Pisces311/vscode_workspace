#include <fstream>
#include <iostream>
#include <vector>

#include "Student.h"
using namespace std;

void Q1(vector<Student> &a, int n) {
    for (int i = 0; i < n; i++) a[i].show();
}

void Q2(vector<Student> &a, int n) {
    for (int i = 0; i < n; i++)
        if (a[i].get_absent_times() >= 2) cout << a[i].get_id() << ' ';
    cout << endl;
}

void Q3(vector<Student> &a, int n, string name) {
    ofstream fout(name);
    for (int i = 0; i < n; i++) {
        fout << a[i].get_id() << ',';
        for (int j = 0; j < 14; j++) {
            fout << a[i].get_score(j) << ",\n"[j == 13];
        }
    }
    fout.close();
}

int main() {
    srand(time(nullptr));
    int n;
    cin >> n;
    vector<Student> a(n);
    Q1(a, n);
    Q2(a, n);
    Q3(a, n, "./lab_records.csv");
    return 0;
}