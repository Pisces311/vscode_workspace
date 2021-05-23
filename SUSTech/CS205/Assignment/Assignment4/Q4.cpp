#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>

#include "Student.h"
using namespace std;

int main() {
    ifstream fin("./lab_records.csv");
    string line;
    vector<Student> a;
    while (getline(fin, line)) {
        istringstream isstr(line);
        string id, num;
        vector<int> s;
        getline(isstr, id, ',');
        for (int i = 0; i < 14; i++) {
            getline(isstr, num, ',');
            s.push_back(atoi(num.c_str()));
        }
        Student stu(id, s);
        a.push_back(stu);
    }
    vector<double> tot(14), avg(14);
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < a.size(); j++) tot[i] += a[j].get_score(i);
        avg[i] = tot[i] / a.size();
    }
    double course_avg = accumulate(avg.begin(), avg.end(), 0.0) / 14;
    for (int i = 0; i < 14; i++)
        if (avg[i] < course_avg) cout << i + 1 << ' ';
    cout << endl;
    return 0;
}