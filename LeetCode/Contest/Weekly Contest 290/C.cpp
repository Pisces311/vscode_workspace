#include <bits/stdc++.h>
using namespace std;

struct query {
    int id, x, y, ans;
};

class Solution {
   public:
    vector<int> countRectangles(vector<vector<int>>& rectangles,
                                vector<vector<int>>& points) {
        int n = points.size();
        sort(rectangles.begin(), rectangles.end(),
             [&](vector<int>& a, vector<int>& b) { return a[0] > b[0]; });
        vector<query> q(n);
        for (int i = 0; i < n; i++) {
            q[i] = {i, points[i][0], points[i][1], 0};
        }
        sort(q.begin(), q.end(), [&](query& a, query& b) { return a.x > b.x; });
        int j = 0;
        vector<int> a(101);
        for (int i = 0; i < n; i++) {
            while (j < rectangles.size() && rectangles[j][0] >= q[i].x) {
                a[rectangles[j][1]]++;
                j++;
            }
            for (int k = q[i].y; k <= 100; k++) {
                q[i].ans += a[k];
            }
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) ans[q[i].id] = q[i].ans;
        return ans;
    }
};