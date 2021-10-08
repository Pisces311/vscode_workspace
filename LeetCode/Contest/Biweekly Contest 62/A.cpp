#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int sz = original.size();
        if (m * n != sz) return {};
        vector<vector<int>> ret(m);
        int k = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ret[i].push_back(original[k]);
                k++;
            }
        }
        return ret;
    }
};