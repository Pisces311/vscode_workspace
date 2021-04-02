#include <fstream>
#include <iostream>
using namespace std;

struct City {
    char name[25];
    char state[25];
    char country[25];
    double latitude;
    double longitude;
} cities[800];

void read_file(ifstream &file) {
    char value[50];
    string line;
    int cnt = 0;
    while (!file.eof()) {
        file.getline(cities[cnt].name, 25, ',');
        file.getline(cities[cnt].state, 25, ',');
        file.getline(cities[cnt].country, 25, ',');
        if (!file.good()) {
            cout << "line too long." << endl;
            return;
        }
        file.getline(value, 50, ',');
        cities[cnt].latitude = atof(value);
        file.getline(value, 50);
        cities[cnt].longitude = atof(value);
        cnt++;
    }
}

int main() {
    ifstream file;
    file.open("world_cities.csv");

    if (file.is_open()) {
        read_file(file);
        file.close();
    } else {
        cout << "The file is missing." << endl;
    }

    return 0;
}