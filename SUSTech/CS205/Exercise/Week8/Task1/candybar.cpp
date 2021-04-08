#include "candybar.h"

#include <iostream>
using namespace std;

void setCandyBar(CandyBar& cb) {
    cout << "Enter brand name of a candy bar: ";
    cin.getline(cb.brand, LEN);
    cout << "Enter weight of the Candy bar: ";
    cin >> cb.weight;
    cout << "Enter calories (an integer value) in the Candy bar: ";
    cin >> cb.calories;
    cin.get();
}

void setCandyBar(CandyBar* cb) {
    cout << "Enter brand name of a candy bar: ";
    cin.getline(cb->brand, LEN);
    cout << "Enter weight of the Candy bar: ";
    cin >> cb->weight;
    cout << "Enter calories (an integer value) in the Candy bar: ";
    cin >> cb->calories;
    cin.get();
}

void showCandyBar(const CandyBar& cb) {
    cout << "Brand: " << cb.brand << endl;
    cout << "Weight: " << cb.weight << endl;
    cout << "Calories: " << cb.calories << endl;
}

void showCandyBar(const CandyBar* cb) {
    cout << "Brand: " << cb->brand << endl;
    cout << "Weight: " << cb->weight << endl;
    cout << "Calories: " << cb->calories << endl;
}