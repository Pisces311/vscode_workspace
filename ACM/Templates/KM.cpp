#include <bits/stdc++.h>
using namespace std;

class KM {
    int n, m;
    vector<int> u, v, p, way;
    vector<vector<int>> A;

   public:
    KM(int n, int m) : n(n), m(m) {
        u.resize(n + 1);
        v.resize(m + 1);
        p.resize(m + 1);
        way.resize(m + 1);
        A.resize(n + 1, vector<int>(m + 1));
    }

    void add_edge(int from, int to, int cost) { A[from + 1][to + 1] = cost; }

    int solve() {
        // Find the maximum matching "vector<pair<int,int>>result;" with all
        // pairs As well as total cost "C" with the minimum assignment cost.
        for (int i = 1; i <= n; ++i) {
            p[0] = i;
            int j0 = 0;
            vector<int> minv(m + 1, INT_MAX);
            vector<char> used(m + 1, false);
            do {
                used[j0] = true;
                int i0 = p[j0], delta = INT_MAX, j1;
                for (int j = 1; j <= m; ++j)
                    if (!used[j]) {
                        int cur = A[i0][j] - u[i0] - v[j];
                        if (cur < minv[j]) minv[j] = cur, way[j] = j0;
                        if (minv[j] < delta) delta = minv[j], j1 = j;
                    }
                for (int j = 0; j <= m; ++j)
                    if (used[j])
                        u[p[j]] += delta, v[j] -= delta;
                    else
                        minv[j] -= delta;
                j0 = j1;
            } while (p[j0] != 0);
            do {
                int j1 = way[j0];
                p[j0] = p[j1];
                j0 = j1;
            } while (j0);
        }

        // vector<pair<int, int>> result;
        // for (int i = 1; i <= m; ++i) {
        //     result.push_back(make_pair(p[i], i));
        // }

        int C = -v[0];
        return C;
    }
};