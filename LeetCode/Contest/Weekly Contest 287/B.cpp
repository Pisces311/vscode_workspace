#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> result;
        for (vector<int>& match : matches) {
            int win = match[0], lose = match[1];
            result[win] += 0;
            result[lose] += 1;
        }
        vector<int> zero, one;
        for (auto i = result.begin(); i != result.end(); i++) {
            if (i->second == 0)
                zero.push_back(i->first);
            else if (i->second == 1)
                one.push_back(i->first);
        }
        return {zero, one};
    }
};