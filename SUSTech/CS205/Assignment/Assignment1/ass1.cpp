#include <math.h>

#include <iostream>
using namespace std;

#define Pi acos(-1)

struct City {
    string name;
    double latitude, longitude;
} a, b;

double rad(double deg) { return deg * Pi / 180; }

double solve() {
    double phi1 = rad(90 - a.latitude), phi2 = rad(90 - b.latitude);
    double theta1 = rad(a.longitude), theta2 = rad(b.longitude);
    double c =
        sin(phi1) * sin(phi2) * cos(theta1 - theta2) + cos(phi1) * cos(phi2);
    return 6347 * acos(c);
}

bool check(string s) {
    for (char ch : s) {
        if (!isalpha(ch) && ch != ',' && ch != ' ') return false;
    }
    return true;
}

int main() {
    cout << "The first city: ";
    getline(cin, a.name);
    if (!check(a.name)) {
        cout << "Invalid input" << endl;
        return 0;
    }
    cout << "The latitude and longitude of first city: ";
    cin >> a.latitude >> a.longitude;
    cin.get();
    cout << "The second city: ";
    getline(cin, b.name);
    if (!check(b.name)) {
        cout << "Invalid input" << endl;
        return 0;
    }
    cout << "The latitude and longitude of second city: ";
    cin >> b.latitude >> b.longitude;
    cout << "The distance between " << a.name << " and " << b.name << " is "
         << solve() << " km" << endl;
    return 0;
}