#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T, n;
priority_queue<int> pq;

bool win() {
    while (pq.size() >= 2) {
        int t1 = pq.top() - 1;
        pq.pop();
        int t2 = pq.top() - 1;
        pq.pop();
        if (t1) pq.push(t1);
        if (t2) pq.push(t2);
    }
    if (pq.empty())
        return false;
    else
        return true;
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
        cin >> n;
        while (!pq.empty()) pq.pop();
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            pq.push(x);
        }
        if (win()) {
            cout << "T\n";
        } else
            cout << "HL\n";
    }

    return 0;
}