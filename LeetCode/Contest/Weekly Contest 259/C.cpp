#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class DetectSquares {
    vector<vector<int>> points;
    map<int, map<int, ll>> m;

   public:
    DetectSquares() {
        points.clear();
        m.clear();
    }

    void add(vector<int> point) {
        points.push_back(point);
        m[point[1]][point[0]]++;
    }

    int count(vector<int> point) {
        int qx = point[0], qy = point[1];
        ll ans = 0;
        for (vector<int> &i : points) {
            if (i[0] != qx && i[1] != qy && abs(qx - i[0]) == abs(qy - i[1])) {
                ans += m[qy][i[0]] * m[i[1]][qx];
            }
        }
        return ans;
    }
};