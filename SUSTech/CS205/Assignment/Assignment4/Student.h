#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Student {
    string SID;
    vector<int> scores;
    int absent_times;
    void set_absent_times();

   public:
    Student();
    Student(string id, vector<int>& s);

    string get_id();
    int get_score(int i);
    int get_absent_times();

    void show();
};