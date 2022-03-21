#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countCollisions(string directions) {
        stack<char> stk;
        int ans = 0;
        for (char ch : directions) {
            if (ch == 'L') {
                if (stk.empty())
                    continue;
                else {
                    if (stk.top() == 'S')
                        ans++;
                    else {
                        ans++;
                        while (!stk.empty() && stk.top() == 'R') {
                            ans++;
                            stk.pop();
                        }
                        stk.push('S');
                    }
                }
            } else if (ch == 'S') {
                while (!stk.empty() && stk.top() == 'R') {
                    ans++;
                    stk.pop();
                }
                stk.push('S');
            } else {
                stk.push(ch);
            }
        }
        return ans;
    }
};