#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans = 0, cur = capacity;
        for (int i = 0; i < plants.size(); i++) {
            if (cur < plants[i]) {
                ans += 2 * i;
                cur = capacity;
            }
            cur -= plants[i];
            ans += 1;
        }
        return ans;
    }
};