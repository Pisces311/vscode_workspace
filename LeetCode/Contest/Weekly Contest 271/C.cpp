#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int cnt = 0;
        int lwater = capacityA, rwater = capacityB;
        for (int l = 0, r = plants.size() - 1; l <= r; l++, r--) {
            if (l != r) {
                if (lwater < plants[l]) {
                    lwater = capacityA;
                    cnt++;
                }
                if (rwater < plants[r]) {
                    rwater = capacityB;
                    cnt++;
                }
                lwater -= plants[l];
                rwater -= plants[r];
            } else {
                if (lwater >= rwater) {
                    if (lwater < plants[l]) cnt++;
                } else if (rwater < plants[r])
                    cnt++;
            }
        }
        return cnt;
    }
};