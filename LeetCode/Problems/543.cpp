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
    int ans;

    int dfs(TreeNode *root) {
        if (!root) return 0;
        int ret1 = dfs(root->left);
        int ret2 = dfs(root->right);
        ans = max(ans, ret1 + ret2);
        return max(ret1, ret2) + 1;
    }

   public:
    int diameterOfBinaryTree(TreeNode *root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};