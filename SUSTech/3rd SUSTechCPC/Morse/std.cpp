#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e3 + 5;

int n;
char s[maxn];
map<string, char> ma;

void init() {
    ma[".-"] = 'A';
    ma["-..."] = 'B';
    ma["-.-."] = 'C';
    ma["-.."] = 'D';
    ma["."] = 'E';
    ma["..-."] = 'F';
    ma["--."] = 'G';
    ma["...."] = 'H';
    ma[".."] = 'I';
    ma[".---"] = 'J';
    ma["-.-"] = 'K';
    ma[".-.."] = 'L';
    ma["--"] = 'M';
    ma["-."] = 'N';
    ma["---"] = 'O';
    ma[".--."] = 'P';
    ma["--.-"] = 'Q';
    ma[".-."] = 'R';
    ma["..."] = 'S';
    ma["-"] = 'T';
    ma["..-"] = 'U';
    ma["...-"] = 'V';
    ma[".--"] = 'W';
    ma["-..-"] = 'X';
    ma["-.--"] = 'Y';
    ma["--.."] = 'Z';
    ma["-----"] = '0';
    ma[".----"] = '1';
    ma["..---"] = '2';
    ma["...--"] = '3';
    ma["....-"] = '4';
    ma["....."] = '5';
    ma["-...."] = '6';
    ma["--..."] = '7';
    ma["---.."] = '8';
    ma["----."] = '9';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    init();
    while (T--) {
        cin >> n;
        assert(n % 2 == 0);
        string tmp;
        for (int i = 1; i <= n; ++i) {
            cin >> tmp;
            s[i] = ma[tmp];
        }
        for (int i = 1; i <= n / 2; ++i) cout << s[i] << s[i + n / 2];
        cout << '\n';
    }

    return 0;
}