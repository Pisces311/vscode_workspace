#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void dfs(vector<int>& preorder, int& rid, int low, int high) {
        if (rid >= preorder.size() || preorder[rid] < low ||
            preorder[rid] > high)
            return;
        int val = preorder[rid++];
        dfs(preorder, rid, low, val);
        dfs(preorder, rid, val, high);
    }

    bool verifyPreorder(vector<int>& preorder) {
        int rid = 0;
        dfs(preorder, rid, INT_MIN, INT_MAX);
        return rid == preorder.size();
    }
};

int main() {
    vector<int> v = {5, 2, 6, 1, 3};
    Solution sol;
    if (sol.verifyPreorder(v)) cout << "YES\n";
    return 0;
}