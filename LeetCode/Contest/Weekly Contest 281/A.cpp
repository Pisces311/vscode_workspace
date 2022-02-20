#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int digitSum(int num) {
        int ret = 0;
        while (num) {
            ret += num % 10;
            num /= 10;
        }
        return ret;
    }

    int countEven(int num) {
        int cnt = 0;
        for (int i = 1; i <= num; i++) {
            if (digitSum(i) & 1) continue;
            cnt++;
        }
        return cnt;
    }
};