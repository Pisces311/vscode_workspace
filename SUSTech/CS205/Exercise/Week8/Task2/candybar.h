#ifndef EXC_CANDYBAR_H
#define EXC_CANDYBAR_H
#include <iostream>

const int LEN = 30;
struct CandyBar {
    char brand[LEN];
    double weight;
    int calories;
};

void setCandyBar(CandyBar& cb);
void setCandyBar(CandyBar* cb);
void showCandyBar(const CandyBar& cb);
void showCandyBar(const CandyBar* cb);

#endif