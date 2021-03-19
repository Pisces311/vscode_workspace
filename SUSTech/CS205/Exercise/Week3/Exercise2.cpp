#include <iostream>
using namespace std;

struct CandyBar {
    char name[25];
    float weight;
    int calory;
    void display() {
        cout << "Brand: " << name << endl;
        cout << "Weight: " << weight << endl;
        cout << "Calories: " << calory << endl;
    }
} candybar;

int main() {
    cout << "Enter brand name of a Candy bar: ";
    cin.getline(candybar.name, 20);
    cout << "Enter weight of the Candy bar: ";
    cin >> candybar.weight;
    cout << "Enter calories (an integer value) in the Candy bar: ";
    cin >> candybar.calory;
    candybar.display();
    return 0;
}