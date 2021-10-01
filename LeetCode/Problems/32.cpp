#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')' && !stk.empty() && s[stk.top()] == '(')
                stk.pop();
            else
                stk.push(i);
        }
        vector<int> invalid;
        while (!stk.empty()) {
            invalid.push_back(stk.top());
            stk.pop();
        }
        reverse(invalid.begin(), invalid.end());
        int l = 0, ans = 0;
        for (int i : invalid) {
            ans = max(ans, i - l);
            l = i + 1;
        }
        return max(ans, (int)s.size() - l);
    }
};