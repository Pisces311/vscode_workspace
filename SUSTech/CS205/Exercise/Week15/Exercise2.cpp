#include <iostream>
#include <numeric>
using namespace std;

class OutOfRangeException : public exception {
   public:
    int id, val;
    OutOfRangeException(int id, int val) : id(id), val(val) {}
};

int main() {
    int num[4];
    char con = 'y';
    while (con == 'y') {
        cout << "Please enter marks for 4 courses: ";
        try {
            for (int i = 0; i < 4; i++) cin >> num[i];
            for (int i = 0; i < 4; i++) {
                if (num[i] < 0 || num[i] > 100) {
                    throw OutOfRangeException(i + 1, num[i]);
                }
            }
            cout << "The average of the four courses is "
                 << accumulate(num, num + 4, 0) / 4.0 << endl;
        } catch (OutOfRangeException &e) {
            cout << "The parameter " << e.id << " is " << e.val
                 << " which out of range (0, 100)." << endl;
        }
        cout << "Would you want to enter another marks for 4 courses (y/n)?";
        cin >> con;
    }
    cout << "Bye, see you next time." << endl;
    return 0;
}