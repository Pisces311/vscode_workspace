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
   public:
    TreeNode *dfs(int val, map<int, vector<int>> &m) {
        TreeNode *u = new TreeNode(val);
        if (m.count(val)) {
            vector<int> v = m[val];
            if (v[0]) u->left = dfs(v[0], m);
            if (v[1]) u->right = dfs(v[1], m);
        }
        return u;
    }

    TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
        map<int, vector<int>> m;
        set<int> notRoot;
        for (vector<int> &des : descriptions) {
            int fa = des[0], ch = des[1], isLeft = des[2];
            notRoot.insert(ch);
            if (!m.count(fa)) {
                m[fa] = vector<int>(2);
            }
            if (isLeft == 1) {
                m[fa][0] = ch;
            } else
                m[fa][1] = ch;
        }
        int root;
        for (auto i = m.begin(); i != m.end(); i++) {
            if (notRoot.count(i->first)) continue;
            root = i->first;
            break;
        }
        return dfs(root, m);
    }
};