#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> dif;
        for (int i : tasks) dif[i]++;
        int ans = 0;
        for (auto i = dif.begin(); i != dif.end(); i++) {
            int num = i->second;
            if (num == 1) return -1;
            if (num % 3 == 0)
                ans += num / 3;
            else if (num % 3 == 1)
                ans += num / 3 + 1;
            else if (num % 3 == 2)
                ans += num / 3 + 1;
        }
        return ans;
    }
};