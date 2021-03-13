#include <iostream>
#include <string>
using namespace std;

struct CandyBar {
    string name;
    float weight;
    int calory;
    void init() {
        cout << "Enter brand name of candy bar: ";
        getline(cin, name);
        cout << "Enter the weight: ";
        cin >> weight;
        cout << "Enter the calories: ";
        cin >> calory;
        cin.get();
    }
    void display() {
        cout << "Brand name: " << name << endl;
        cout << "Weight: " << weight << endl;
        cout << "Calories: " << calory << endl;
    }
};

int main() {
    CandyBar *candybar = new CandyBar[3];
    cout << "Please input three CandyBar's information:" << endl;
    for (int i = 0; i < 3; ++i) {
        candybar[i].init();
    }
    cout << endl;
    cout << "Displaying the CandyBar array contents" << endl;
    for (int i = 0; i < 3; ++i) candybar[i].display();
    cout << endl;
    return 0;
}