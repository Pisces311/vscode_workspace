#include "sales.h"

#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;

void SALES::setSales(Sales& s, const double ar[], int n) {
    int num = min(n, 4);
    cout << num << endl;
    copy(ar, ar + num, s.sales);
    s.average = accumulate(s.sales, s.sales + num, 0.0) / num;
    s.max = *max_element(s.sales, s.sales + num);
    s.min = *min_element(s.sales, s.sales + num);
}

void SALES::setSales(Sales& s) {
    cout << "Enter sales for 4 quarters: ";
    for (int i = 0; i < 4; i++) cin >> s.sales[i];
    s.average = accumulate(s.sales, s.sales + 4, 0.0) / 4;
    s.max = *max_element(s.sales, s.sales + 4);
    s.min = *min_element(s.sales, s.sales + 4);
}

void SALES::showSales(const Sales& s) {
    cout << "Sales:";
    for (int i = 0; i < 4; i++)
        if (s.sales[i]) cout << s.sales[i] << ' ';
    cout << endl;
    cout << "Average:" << s.average << endl;
    cout << "Max:" << s.max << endl;
    cout << "Min:" << s.min << endl;
}
