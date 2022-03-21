#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int check(int mask, int numArrows, vector<int>& a) {
        int score = 0;
        for (int i = 0; i < 12; i++) {
            if (mask & (1 << i)) {
                numArrows -= a[i] + 1;
                if (numArrows < 0) return -1;
                score += i;
            }
        }
        return score;
    }

    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int ans = 0;
        vector<int> res(12);
        for (int mask = 0; mask < (1 << 12); mask++) {
            int score = check(mask, numArrows, aliceArrows);
            if (ans < score) {
                ans = score;
                int tot = numArrows;
                for (int i = 0; i < 12; i++) {
                    if (mask & (1 << i)) {
                        res[i] = aliceArrows[i] + 1;
                        tot -= res[i];
                    } else
                        res[i] = 0;
                }
                res[11] += tot;
            }
        }
        return res;
    }
};