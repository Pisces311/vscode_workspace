#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minDeletion(vector<int>& nums) {
        stack<int> stk;
        for (int i : nums) {
            if (stk.size() % 2 == 0)
                stk.push(i);
            else if (stk.top() != i)
                stk.push(i);
        }
        if (stk.size() % 2 == 1) stk.pop();
        return nums.size() - stk.size();
    }
};