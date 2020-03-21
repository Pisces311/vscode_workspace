#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define ite(i, a, b) for (int i = a; i <= b; ++i)

const int maxn = 1e5 + 1;

int n, m, k;
int pos[maxn];
priority_queue<int, vector<int>, greater<int>> dis;

int main() {
    ios::sync_with_stdio(false);

    // freopen("D:\in.txt", "r", stdin);

    cin >> n >> m >> k;
    ite(i, 1, n) {
        cin >> pos[i];
        if (i != 1) dis.push(pos[i] - pos[i - 1]);
    }

    ll ans = n;
    ite(i, 1, n - k) {
        ans += dis.top() - 1;
        dis.pop();
    }

    cout << ans << endl;

    return 0;
}