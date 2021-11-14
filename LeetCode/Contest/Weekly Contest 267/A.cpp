#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int ans = 0;
        while (tickets[k]) {
            for (int i = 0; i < n; i++) {
                if (tickets[i]) {
                    tickets[i]--;
                    ans++;
                    if (!tickets[k]) break;
                }
            }
        }
        return ans;
    }
};