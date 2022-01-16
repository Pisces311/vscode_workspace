#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minMoves(int target, int maxDoubles) {
        int cnt = 0;
        if (target == 1) return cnt;
        while (maxDoubles) {
            if (target & 1) {
                target -= 1;
                cnt++;
                if (target == 1) return cnt;
            }
            target /= 2;
            cnt++;
            maxDoubles--;
            if (target == 1) return cnt;
        }
        return cnt + target - 1;
    }
};