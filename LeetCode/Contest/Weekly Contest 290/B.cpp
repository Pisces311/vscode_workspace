#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool inside(int x, int y, vector<int>& cir) {
        int cx = cir[0], cy = cir[1], r = cir[2];
        return (x - cx) * (x - cx) + (y - cy) * (y - cy) <= r * r;
    }

    int countLatticePoints(vector<vector<int>>& circles) {
        int ans = 0;
        for (int i = 0; i <= 200; i++) {
            for (int j = 0; j <= 200; j++) {
                for (vector<int>& cir : circles) {
                    if (inside(i, j, cir)) {
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};