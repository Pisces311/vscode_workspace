#include <iostream>
using namespace std;

struct Pizza {
    string name;
    int diameter;
    double weight;
    void display() {
        cout << "Company name: " << name << endl;
        cout << "Pizza diameter: " << diameter << " inches" << endl;
        cout << "Pizza weight: " << weight << " g" << endl;
    }
};

int main() {
    Pizza *p = new Pizza;
    cout << "Enter the name of pizza company: ";
    getline(cin, p->name);
    cout << "Enter the diameter of pizza (inches): ";
    cin >> p->diameter;
    cout << "Enter the weight of the pizza (g): ";
    cin >> p->weight;
    cout << "Displaying the information of the pizza" << endl;
    p->display();
    return 0;
}