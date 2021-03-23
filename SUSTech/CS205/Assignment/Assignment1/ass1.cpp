#include <math.h>

#include <iostream>
using namespace std;

#define Pi acos(-1)

struct City {
    string name;
    double latitude, longitude;
} a, b;

string ord[2] = {"first", "second"};

double rad(double deg) { return deg * Pi / 180; }

double solve() {
    double phi1 = rad(90 - a.latitude), phi2 = rad(90 - b.latitude);
    double theta1 = rad(a.longitude), theta2 = rad(b.longitude);
    double c =
        sin(phi1) * sin(phi2) * cos(theta1 - theta2) + cos(phi1) * cos(phi2);
    return 6347 * acos(c);
}

bool is_name(string s) {
    for (char ch : s) {
        if (!isalpha(ch) && ch != ',' && ch != ' ') return false;
    }
    return true;
}

bool is_double(string s) {
    char* end = 0;
    double val = strtod(s.c_str(), &end);
    return end != s.c_str() && *end == '\0' && val != HUGE_VAL;
}

double get_info(City& city, int id) {
    cout << "The " << ord[id] << " city: ";
    getline(cin, city.name);
    if (!is_name(city.name)) return false;
    cout << "The latitude and longitude of " << ord[id] << " city: ";
    string nums;
    getline(cin, nums);
    int pos = nums.find(" ");
    string a = nums.substr(0, pos);
    string b = nums.substr(pos + 1, nums.size());
    if (!is_double(a) || !is_double(b)) return false;
    city.latitude = atof(a.c_str());
    city.longitude = atof(b.c_str());
    return true;
}

int main() {
    if (get_info(a, 0) && get_info(b, 1)) {
        cout << "The distance between " << a.name << " and " << b.name << " is "
             << solve() << " km" << endl;
    } else
        cout << "Invalid input." << endl;
    return 0;
}