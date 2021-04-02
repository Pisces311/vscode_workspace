#include <iostream>
using namespace std;

struct City {
    char name[50];
    char state[50];
    char country[50];
    double latitude;
    double longitude;
} cities[1000];

int main() {
    freopen("world_cities.csv", "r", stdin);
    char line[200], value[50];
    int cnt = 0;
    while (cin.getline(line, 200)) {
        cin.getline(cities[cnt].name, 50, ',');
        cin.getline(cities[cnt].state, 50, ',');
        cin.getline(cities[cnt].country, 50, ',');
        cin.getline(value, 50, ',');
        cities[cnt].latitude = atof(value);
        cin.getline(value, 50, ',');
        cities[cnt].longitude = atof(value);
        cnt++;
    }
    for (int i = 0; i < 10; i++) {
        cout << cities[i].name << endl;
        cout << cities[i].state << endl;
        cout << cities[i].country << endl;
        cout << cities[i].latitude << ' ' << cities[i].longitude << endl;
    }
    return 0;
}