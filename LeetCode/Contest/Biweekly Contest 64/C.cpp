#include <bits/stdc++.h>
using namespace std;

template <class T>
class BIT {
    vector<T> c;
    T sum(int x) {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i) ans += c[i];
        return ans;
    }

   public:
    BIT(int n) : c(vector<T>(n + 1)) {}

    // 1-based
    BIT(vector<T>& a) : c(vector<T>(a.size() + 1)) {
        for (int i = 0; i < a.size(); i++) update(i + 1, a[i]);
    }

    T getSum(int l, int r) { return sum(r) - sum(l - 1); }

    void update(int x, T val) {
        for (int i = x; i < c.size(); i += i & -i) c[i] += val;
    }
};

class Solution {
   public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        BIT<int> bit(n + 1);
        for (int i = 0; i < n; i++)
            if (s[i] == '*') bit.update(i + 1, 1);
        vector<int> next(n), prev(n);
        int id = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '|') id = i;
            prev[i] = id;
        }
        id = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '|') id = i;
            next[i] = id;
        }
        vector<int> ans;
        for (vector<int>& q : queries) {
            int l = next[q[0]], r = prev[q[1]];
            if (l != -1 && r != -1 && l <= r)
                ans.push_back(bit.getSum(l + 1, r + 1));
            else
                ans.push_back(0);
        }
        return ans;
    }
};