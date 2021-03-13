#include <iostream>
using namespace std;

using ll = long long;

int main() {
    ll sec;
    cout << "Enter the number of seconds:";
    cin >> sec;
    cout << sec << " seconds = ";
    ll days = sec / 60 / 60 / 24;
    cout << days << " days, ";
    sec -= days * 24 * 60 * 60;
    ll hours = sec / 60 / 60;
    cout << hours << " hours, ";
    sec -= hours * 60 * 60;
    ll mins = sec / 60;
    cout << mins << " minutes, ";
    sec -= mins * 60;
    cout << sec << " seconds" << endl;
    return 0;
}