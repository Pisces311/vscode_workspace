#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
int x, y, dx, dy;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    vector<vector<int> > mat(n, vector<int>(m));
    for (int i = 0; i < k; ++i) {
        cin >> x >> y >> dx >> dy;
        for (int px = x, py = y; 0 <= px && px < n && 0 <= py && y < m;
             px += dx, py += dy)
            mat[px][py] = 1;
    }
    int ans = 0;
    for (auto x : mat)
        for (auto y : x)
            if (!y) ++ans;
    cout << ans << '\n';

    return 0;
}