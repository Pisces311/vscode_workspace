#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

class Solution {
   public:
    int minimumOperations(vector<int>& nums) {
        vector<int> odd, even;
        for (int i = 0; i < nums.size(); i++) {
            if (i & 1)
                odd.push_back(nums[i]);
            else
                even.push_back(nums[i]);
        }
        int on = odd.size(), en = even.size();
        map<int, int> omap, emap;
        for (int i : odd) omap[i]++;
        for (int i : even) emap[i]++;
        pii omost(0, 0), osecond(0, 0), emost(0, 0), esecond(0, 0);
        for (auto i = omap.begin(); i != omap.end(); i++) {
            if (i->second > omost.second) {
                osecond = omost;
                omost = make_pair(i->first, i->second);
            } else if (i->second > osecond.second) {
                osecond = make_pair(i->first, i->second);
            }
        }
        for (auto i = emap.begin(); i != emap.end(); i++) {
            if (i->second > emost.second) {
                esecond = emost;
                emost = make_pair(i->first, i->second);
            } else if (i->second > esecond.second) {
                esecond = make_pair(i->first, i->second);
            }
        }
        if (omost.first != emost.first) {
            return on - omost.second + en - emost.second;
        } else {
            return min(on - omost.second + en - esecond.second,
                       on - osecond.second + en - emost.second);
        }
    }
};