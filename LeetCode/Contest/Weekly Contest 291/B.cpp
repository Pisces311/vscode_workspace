#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimumCardPickup(vector<int>& cards) {
        map<int, int> ma;
        int ans = INT_MAX;
        for (int i = 0; i < cards.size(); i++) {
            int card = cards[i];
            if (ma.count(card)) {
                ans = min(ans, i - ma[card] + 1);
            }
            ma[card] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};