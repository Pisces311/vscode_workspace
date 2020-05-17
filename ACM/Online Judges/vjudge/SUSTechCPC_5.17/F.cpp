#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 3e5 + 5;

int n;
int x[maxn], y[maxn];
vector<int> convex;

int dis(int i, int j) { return abs(x[i] - x[j]) + abs(y[i] - y[j]); }

int cal(int i, int j, int k) { return dis(i, j) + dis(j, k) + dis(k, i); }

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
    int x_max = *max_element(x + 1, x + n + 1);
    int x_min = *min_element(x + 1, x + n + 1);
    int y_max = *max_element(y + 1, y + n + 1);
    int y_min = *min_element(y + 1, y + n + 1);
    for (int i = 1; i <= n; ++i)
        if (x[i] == x_max || x[i] == x_min || y[i] == y_max || y[i] == y_min)
            convex.push_back(i);
    if (convex.size() == 2) {
        cout << 2 * (x_max - x_min + y_max - y_min) << ' ';
    } else {
        int Max = -1;
        for (int i = 0; i < convex.size(); ++i) {
            for (int j = i + 1; j < convex.size(); ++j) {
                for (int k = 1; k <= n; ++k) {
                    if (k > convex[i] && k < convex[j]) {
                        Max = max(Max, cal(convex[i], k, convex[j]));
                    } else if (k < convex[i] || k > convex[j]) {
                        Max = max(Max, cal(convex[i], convex[j], k));
                    }
                }
            }
        }
        cout << Max << ' ';
    }
    for (int i = 4; i <= n; ++i)
        cout << 2 * (x_max - x_min + y_max - y_min) << ' ';
    cout << '\n';

    return 0;
}