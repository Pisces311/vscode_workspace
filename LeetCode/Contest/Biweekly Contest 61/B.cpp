#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int, int> Map;
        for (int i = 0; i < changed.size(); i++) Map[changed[i]]++;
        vector<int> ret;
        for (auto i = Map.begin(); i != Map.end(); i++) {
            if (i->second == 0) continue;
            if (i->first == 0) {
                if (i->second & 1)
                    return {};
                else {
                    for (int _ = 0; _ < i->second / 2; _++)
                        ret.push_back(i->first);
                    i->second = 0;
                }
            } else if (Map[2 * i->first] < i->second)
                return {};
            else {
                for (int _ = 0; _ < i->second; _++) ret.push_back(i->first);
                Map[2 * i->first] -= i->second;
                i->second = 0;
            }
        }
        return ret;
    }
};