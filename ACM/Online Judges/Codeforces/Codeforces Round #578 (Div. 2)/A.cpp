#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int n;
char s[maxn];
int room[20];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin >> (s + 1);
    int len = strlen(s + 1);
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'L') {
            for (int j = 0; j <= 9; ++j)
                if (room[j] == 0) {
                    room[j] = 1;
                    break;
                }
        } else if (s[i] == 'R') {
            for (int j = 9; j >= 0; --j)
                if (room[j] == 0) {
                    room[j] = 1;
                    break;
                }
        } else
            room[s[i] - '0'] = 0;
    }
    for (int i = 0; i <= 9; ++i) cout << room[i];
    cout << '\n';

    return 0;
}