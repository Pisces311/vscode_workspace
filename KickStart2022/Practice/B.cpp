#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    set<char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        string str;
        cin >> str;
        cout << "Case #" << tc << ": " << str << " is ruled by ";
        if (str.back() == 'y' || str.back() == 'Y')
            cout << "nobody.\n";
        else if (vowels.count(str.back()))
            cout << "Alice.\n";
        else
            cout << "Bob.\n";
    }

    return 0;
}