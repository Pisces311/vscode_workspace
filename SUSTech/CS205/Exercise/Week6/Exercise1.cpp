#include <iostream>
using namespace std;

int main() {
    cout << "=====================================" << endl;
    cout << "\t\tMENU\t\t" << endl;
    cout << "=====================================" << endl;
    cout << "\t1.Add" << endl;
    cout << "\t2.Subtract" << endl;
    cout << "\t3.Multiply" << endl;
    cout << "\t4.Divide" << endl;
    cout << "\t5.Modulus" << endl;
    char con;
    do {
        cout << "Enter your choice(1~5):";
        int choice;
        cin >> choice;
        cout << "Enter your integer numbers:";
        int a, b;
        cin >> a >> b;
        cout << endl;
        cout << "Result:";
        if (choice == 1) cout << a + b << endl;
        else if (choice == 2) cout << a - b << endl;
        else if (choice == 3) cout << a * b << endl;
        else if (choice == 4) cout << a / b << endl;
        else cout << a % b << endl;
        cout << "Press y or Y to continue:";
        cin >> con;
    } while (con == 'y' || con == 'Y');
    return 0;
}