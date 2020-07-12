#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e3 + 5;

int T;
char s[maxn], code[27];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    int cas = 0;
    while (T--) {
        cout << "Case #" << ++cas << ": ";
        int dry = 0, wet = 0, harmful = 0;
        cin >> (s + 1) >> (code + 1);
        int len = strlen(s + 1);
        for (int i = 1; i <= len; ++i) {
            int pos = s[i] - 'a' + 1;
            if (code[pos] == 'w')
                ++wet;
            else if (code[pos] == 'd')
                ++dry;
            else
                ++harmful;
        }
        if (1.0 * harmful >= 1.0 * len / 4) {
            cout << "Harmful" << '\n';
        } else if (1.0 * harmful <= 1.0 * len / 10) {
            cout << "Recyclable" << '\n';
        } else if (dry >= 2 * wet) {
            cout << "Dry" << '\n';
        } else
            cout << "Wet" << '\n';
    }

    return 0;
}