#include <iostream>
#include <vector>
using namespace std;

int m, n;

void fill(vector<vector<int> > &mat, int &cur, int l, int r, int u, int d) {
    if (l > r || u > d) return;
    for (int i = r; i >= l; --i) mat[u][i] = cur++;
    if (d > u) {
        for (int i = u + 1; i <= d; ++i) mat[i][l] = cur++;
        for (int i = l + 1; i <= r; ++i) mat[d][i] = cur++;
        if (l != r) for (int i = d - 1; i > u; --i) mat[i][r] = cur++;
    }
    fill(mat, cur, l + 1, r - 1, u + 1, d - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;
    int cur = 1;
    vector<vector<int> > mat(m, vector<int>(n));
    fill(mat, cur, 0, n - 1, 0, m - 1);
    for (auto i : mat) {
        for (auto j : i) cout << j << ' ';
        cout << '\n';
    }

    return 0;
}