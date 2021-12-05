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
    vector<int> depth, fa;
    vector<vector<int>> son;
    string ans;

   public:
    void dfs(TreeNode *root, int d, int f) {
        depth[root->val] = d;
        fa[root->val] = f;
        if (root->left) {
            son[root->val].push_back(root->left->val);
            dfs(root->left, d + 1, root->val);
        } else
            son[root->val].push_back(-1);
        if (root->right) {
            son[root->val].push_back(root->right->val);
            dfs(root->right, d + 1, root->val);
        } else
            son[root->val].push_back(-1);
    }

    int findN(TreeNode *root) {
        if (!root) return 0;
        return max({root->val, findN(root->left), findN(root->right)});
    }

    void init(TreeNode *root, int startValue, int destValue) {
        int n = findN(root);
        depth.resize(n + 1);
        fa.resize(n + 1);
        for (int i = 1; i <= n; i++) depth[i] = fa[i] = 0;
        son.resize(n + 1);
        for (int i = 1; i <= n; i++) son[i].clear();
        ans = "";
        dfs(root, 0, -1);
    }

    string getDirections(TreeNode *root, int startValue, int destValue) {
        init(root, startValue, destValue);

        int s = startValue, d = destValue;
        while (depth[s] != depth[d]) {
            if (depth[s] > depth[destValue])
                s = fa[s];
            else
                d = fa[d];
        }
        while (s != d) {
            s = fa[s];
            d = fa[d];
        }
        int r = s;
        fa[r] = -1;
        while (fa[destValue] != -1) {
            int f = fa[destValue];
            if (son[f][0] == destValue)
                ans += 'L';
            else
                ans += 'R';
            destValue = f;
        }
        reverse(ans.begin(), ans.end());
        string ret = "";
        for (int i = 0; i < depth[startValue] - depth[r]; i++) ret += 'U';
        return ret + ans;
    }
};