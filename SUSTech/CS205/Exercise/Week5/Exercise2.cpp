#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

string str;
 
vector<string> split(string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

int solve() {
    int cnt = 0;
    while (true) {
        getline(cin, str);
        vector<string> v = split(str, ' ');
        for (string s: v) {
            if (s != "done") cnt++;
            else
                return cnt;
        }
    }
}

int main() {
    cout << "Enter words(to stop, type the word done):" << endl;
    int ans = solve();
    cout << "You entered a total of " << ans << " words." << endl;
    return 0;
}