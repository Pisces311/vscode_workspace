#include <bits/stdc++.h>
using namespace std;

struct node {
    int id, dis;
    bool operator<(const node& a) const { return dis > a.dis; }
};

class Solution {
   public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> g(n + 1);
        for (vector<int>& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<vector<int>> dis(n + 1, vector<int>(2));
        for (int i = 1; i <= n; i++) {
            dis[i][0] = INT_MAX - 1;
            dis[i][1] = INT_MAX;
        }
        priority_queue<node> pq;
        pq.push({1, 0});
        while (!pq.empty()) {
            node u = pq.top();
            pq.pop();
            if (u.dis < dis[u.id][0]) {
                swap(dis[u.id][0], dis[u.id][1]);
                dis[u.id][0] = u.dis;
            } else if (u.dis != dis[u.id][0] && u.dis < dis[u.id][1]) {
                dis[u.id][1] = u.dis;
            } else
                continue;
            for (int v : g[u.id]) {
                int seg = u.dis / change, d;
                if (seg & 1)
                    d = (u.dis / change + 1) * change + time;
                else
                    d = u.dis + time;
                pq.push({v, d});
            }
        }
        return dis[n][1];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges = {{1, 2}};
    cout << sol.secondMinimum(2, edges, 1, 2) << endl;
    return 0;
}

// 3142