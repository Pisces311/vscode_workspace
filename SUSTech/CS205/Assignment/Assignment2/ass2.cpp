#include <math.h>
#include <string.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

#define length 35
#define array_size 1000
#define Pi acos(-1)

struct City {
    char name[length];
    char country[length];
    double latitude;
    double longitude;
} cities[array_size];

int read_file(ifstream &file) {
    char value[50];
    string line;
    int cnt = 0;
    while (getline(file, line)) {
        stringstream data(line);
        data.getline(cities[cnt].name, length, ',');
        char foo[50];
        data.getline(foo, 50, ',');
        data.getline(cities[cnt].country, length, ',');
        if (data.fail()) {
            cout << "Data is truncated." << endl;
            return -1;
        }
        data.getline(value, 50, ',');
        cities[cnt].latitude = atof(value);
        data.getline(value, 50);
        cities[cnt].longitude = atof(value);
        cnt++;
        if (cnt == array_size) {
            cout << "Data is not loaded." << endl;
            return -1;
        }
    }
    return cnt;
}

char *trim(char *str) {
    char *point = str;
    while (*point != '\0') point++;
    point--;
    while (point >= str && *point == ' ') {
        *point = '\0';
        point--;
    }
    point = str;
    while (*point == ' ') point++;
    return point;
}

int select_city(int n) {
    char *name = new char[length];
    while (true) {
        cin.getline(name, length);
        name = trim(name);
        if (!strcmp(name, "bye")) return -1;
        vector<int> match;
        for (int i = 0; i < n; ++i) {
            if (strstr(cities[i].name, name) != nullptr) match.push_back(i);
        }
        if (strlen(name) < 3 || match.empty())
            cout << "Name is invalid." << endl;
        else {
            if (match.size() > 1) {
                cout << "Please select the right one by choosing the id."
                     << endl;
                int id = 0;
                for (int i : match)
                    cout << ++id << ": " << cities[i].name << endl;
                int choose;
                cin >> choose;
                cin.get();
                return match[choose - 1];
            } else
                return match.front();
        }
    }
}

double rad(double deg) { return deg * Pi / 180; }

double solve(const City &a, const City &b) {
    double phi1 = rad(90 - a.latitude), phi2 = rad(90 - b.latitude);
    double theta1 = rad(a.longitude), theta2 = rad(b.longitude);
    double c =
        sin(phi1) * sin(phi2) * cos(theta1 - theta2) + cos(phi1) * cos(phi2);
    return 6347 * acos(c);
}

int main() {
    ifstream file;
    file.open("world_cities.csv");

    if (file.is_open()) {
        int n = read_file(file);
        file.close();
        if (n == -1) return 0;
        while (true) {
            cout << "Please input the name of the first city: ";
            int id = select_city(n);
            if (id == -1) return 0;
            City a = cities[id];
            cout << "City selected: " << a.name << endl;
            cout << "Please input the name of the second city: ";
            City b = cities[select_city(n)];
            cout << "City selected: " << b.name << endl;
            cout << "The distance between " << a.name << " and " << b.name
                 << " is " << solve(a, b) << " km" << endl;
        }
    } else {
        cout << "The file is missing." << endl;
    }

    return 0;
}