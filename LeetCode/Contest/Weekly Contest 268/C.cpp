#include <bits/stdc++.h>
using namespace std;

class RangeFreqQuery {
    vector<vector<int>> occur;

   public:
    RangeFreqQuery(vector<int>& arr) {
        occur.resize(10005);
        for (auto& i : occur) i.clear();
        for (int i = 0; i < arr.size(); i++) occur[arr[i]].push_back(i);
    }

    int query(int left, int right, int value) {
        vector<int>& tar = occur[value];
        int p1 = lower_bound(tar.begin(), tar.end(), left) - tar.begin();
        int p2 = upper_bound(tar.begin(), tar.end(), right) - tar.begin();
        return p2 - p1;
    }
};