#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int limit = 2e9;

        sort(tiles.begin(), tiles.end());
        int n = tiles.size();
        tiles.push_back({limit, limit});
        vector<int> presum(n + 1);
        for (int i = 1; i <= n; i++) {
            presum[i] = presum[i - 1] + tiles[i - 1][1] - tiles[i - 1][0] + 1;
        }
        int ans = 0;
        for (int i = 0, j = 0; i < n; i++) {
            int l = tiles[i][0], r = l + carpetLen - 1;
            while (j < n && tiles[j][1] <= r) j++;
            ans = max(ans, presum[j] - presum[i] + max(0, r - tiles[j][0] + 1));
        }
        return ans;
    }
};