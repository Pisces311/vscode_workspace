#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

char op;
int n, x;
queue<int> q;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    while (n--) {
        cin >> op;
        if (op == 'E') {
            cin >> x;
            q.push(x);
        } else if (op == 'D')
            q.pop();
        else
            cout << q.front() << '\n';
    }
    while (q.size()) {
        cout << q.front() << ' ';
        q.pop();
    }
    cout << '\n';

    return 0;
}