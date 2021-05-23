#include "Student.h"

#include <iostream>
using namespace std;

int random(int a, int b) { return (rand() % (b - a + 1)) + a; }

void Student::set_absent_times() {
    absent_times = 0;
    for (auto i = scores.begin(); i != scores.end(); i++)
        if (!(*i)) absent_times++;
}

Student::Student() {
    SID = to_string(random(20000000, 20209999));
    scores.resize(14);
    for (auto i = scores.begin(); i != scores.end(); i++) *i = random(0, 5);
    set_absent_times();
}

Student::Student(string id, vector<int> &s) : SID(id), scores(s) {
    set_absent_times();
}

string Student::get_id() { return SID; }

int Student::get_score(int i) { return scores[i]; }

int Student::get_absent_times() { return absent_times; }

void Student::show() {
    cout << SID << ": ";
    for (int i = 0; i < 14; i++) cout << scores[i] << ' ';
    cout << endl;
}