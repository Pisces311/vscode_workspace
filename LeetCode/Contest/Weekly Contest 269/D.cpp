#include <bits/stdc++.h>
using namespace std;

struct node {
    int i, t;
    const bool operator<(const node& a) const { return t > a.t; }
};

class Solution {
   public:
    int bsearch(vector<vector<int>>& v, int tar) {
        int l = 0, r = v.size() - 1, ans = v.size();
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (v[mid][1] < tar)
                l = mid + 1;
            else {
                r = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {
        vector<vector<vector<int>>> g(n);
        for (vector<int>& edge : meetings) {
            int u = edge[0], v = edge[1], t = edge[2];
            g[u].push_back({v, t});
            g[v].push_back({u, t});
        }
        for (int i = 0; i < n; i++) {
            sort(g[i].begin(), g[i].end(),
                 [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
        }
        vector<int> dis(n, 0x3f3f3f3f);
        dis[0] = dis[firstPerson] = 0;
        priority_queue<node> pq;
        pq.push({0, 0});
        pq.push({firstPerson, 0});
        while (!pq.empty()) {
            node top = pq.top();
            pq.pop();
            if (top.t > dis[top.i]) continue;
            int u = top.i;
            int id = bsearch(g[u], dis[u]);
            for (int i = id; i < g[u].size(); i++) {
                int v = g[u][i][0], t = g[u][i][1];
                if (t < dis[v]) {
                    dis[v] = t;
                    pq.push({v, dis[v]});
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (dis[i] != 0x3f3f3f3f) ans.push_back(i);
        return ans;
    }
};