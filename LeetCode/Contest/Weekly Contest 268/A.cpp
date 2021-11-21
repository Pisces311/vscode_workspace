#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxDistance(vector<int>& colors) {
        int ans = -1;
        for (int i = 0; i < colors.size(); i++) {
            for (int j = 0; j < colors.size(); j++) {
                if (colors[i] != colors[j]) ans = max(ans, abs(i - j));
            }
        }
        return ans;
    }
};