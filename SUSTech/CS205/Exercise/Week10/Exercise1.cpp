#include <iostream>
#include <string>
using namespace std;

class CandyBar {
    string name;
    double weight;
    int calories;

   public:
    void setCandyBar() {
        cout << "Enter brand name of a candy bar: ";
        getline(cin, name);
        cout << "Enter weight of the candy bar: ";
        cin >> weight;
        cout << "Enter calories(an integer value) in the candy bar: ";
        cin >> calories;
    }

    void showCandyBar() {
        cout << "Brand: " << name << endl;
        cout << "Weight: " << weight << endl;
        cout << "Calories: " << calories << endl;
    }
};

int main() {
    CandyBar candybar;
    candybar.setCandyBar();
    candybar.showCandyBar();
    return 0;
}