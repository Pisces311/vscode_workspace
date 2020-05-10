#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;
const int maxn = 1e4 + 5;

struct node {
    int dis;
    int fuel;
    bool operator<(const node &a) const { return dis > a.dis; }
} stop[maxn];

int n, l, p;
priority_queue<int> pq;

int main() {
#ifdef DEBUG
    freopen("SUSTech/CS203/2020Spring/Quiz 2/C/Input/7.in", "r", stdin);
    freopen("SUSTech/CS203/2020Spring/Quiz 2/C/Output/7.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> stop[i].dis >> stop[i].fuel;
    cin >> l >> p;
    sort(stop, stop + n);
    pq.push(p);
    int id = 0, ans = 0;
    while (l > 0 && !pq.empty()) {
        ++ans;
        l -= pq.top();
        pq.pop();
        while (l <= stop[id].dis && id < n) pq.push(stop[id++].fuel);
    }
    if (l > 0)
        cout << "-1\n";
    else
        cout << ans - 1 << '\n';

    return 0;
}