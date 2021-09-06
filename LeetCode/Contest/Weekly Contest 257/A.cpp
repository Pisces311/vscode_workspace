#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countQuadruplets(vector<int>& nums) {
        int cnt = 0;
        for (int d = 3; d < nums.size(); d++) {
            for (int c = 2; c < d; c++) {
                for (int b = 1; b < c; b++) {
                    for (int a = 0; a < b; a++) {
                        if (nums[a] + nums[b] + nums[c] == nums[d]) cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};

int main() {
    Solution a;
    vector<int> v = {1,1,1,3,5};
    cout << a.countQuadruplets(v) << endl;
    return 0;
}