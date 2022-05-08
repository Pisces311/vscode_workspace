#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
    using pii = pair<int, int>;

    int ans;

    pii dfs(TreeNode *root) {
        int tot = root->val, cnt = 1;
        if (root->left) {
            pii ret = dfs(root->left);
            tot += ret.first;
            cnt += ret.second;
        }
        if (root->right) {
            pii ret = dfs(root->right);
            tot += ret.first;
            cnt += ret.second;
        }
        if (root->val == tot / cnt) ans++;
        return {tot, cnt};
    }

   public:
    int averageOfSubtree(TreeNode *root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};