#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int maxn = 26;

int T, S;
stack<pii> stk;
char mat[maxn][maxn];

inline void init() {
    while (!stk.empty()) stk.pop();
    for (int i = 1; i <= 25; ++i)
        for (int j = 1; j <= 25; ++j) mat[i][j] = '.';
}

void print() {
    cout << 25 << ' ' << 25 << '\n';
    while (!stk.empty()) {
        pii top = stk.top();
        stk.pop();
        mat[top.first][top.second] = 'X';
    }
    for (int i = 1; i <= 25; ++i) {
        for (int j = 1; j <= 25; ++j)
            if (mat[i][j] != 'X')
                cout << '.';
            else
                cout << 'X';
        cout << '\n';
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        init();
        cin >> S;
        if (S == 0)
            cout << "1 1\n.\n";
        else if (S == 1)
            cout << "1 2\n.X\n";
        else if (S == 2)
            cout << "1 3\n.X.\n";
        else if (S == 4)
            cout << "2 2\n.X\nX.\n";
        else if (S == 6)
            cout << "2 3\nXX.\n...\n";
        else if (S == 7)
            cout << "2 3\nX.X\n.X.\n";
        else if (S == 12)
            cout << "3 3\nX.X\n...\nX.X\n";
        else {
            pii pos = make_pair(2, 4);
            while (S >= 8) {
                stk.push(pos);
                S -= 8;
                pos.second += 2;
                if (pos.second > 25 || (pos.first == 2 && pos.second == 24))
                    pos = make_pair(pos.first + 2, 2);
            }
            if (S == 1) {
                stk.pop();
                stk.push(make_pair(1, 1));
                stk.push(make_pair(1, 25));
                stk.push(make_pair(25, 25));
            } else if (S == 2) {
                stk.pop();
                stk.push(make_pair(25, 22));
                stk.push(make_pair(25, 24));
            } else if (S == 3)
                stk.push(make_pair(1, 1));
            else if (S == 4) {
                stk.pop();
                stk.pop();
                stk.push(make_pair(23, 23));
                stk.push(make_pair(23, 24));
                stk.push(make_pair(24, 23));
                stk.push(make_pair(24, 24));
            } else if (S == 5) {
                stk.push(make_pair(25, 24));
            } else if (S == 6)
                stk.push(make_pair(stk.top().first + 1, stk.top().second));
            else if (S == 7) {
                stk.pop();
                stk.push(make_pair(25, 20));
                stk.push(make_pair(25, 22));
                stk.push(make_pair(25, 24));
            }
            print();
        }
    }

    return 0;
}