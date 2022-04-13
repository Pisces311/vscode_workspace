#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i : nums) pq.push(i);
        while (k--) {
            int top = pq.top();
            pq.pop();
            pq.push(top + 1);
        }
        long long ans = 1, mod = 1e9 + 7;
        while (!pq.empty()) {
            ans = (ans * pq.top()) % mod;
            pq.pop();
        }
        return ans;
    }
};