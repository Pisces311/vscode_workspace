#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    vector<TreeNode *> generateTrees(int n) { return genTrees(1, n); }

    vector<TreeNode *> genTrees(int start, int end) {
        vector<TreeNode *> res;
        if (start > end) {
            res.push_back(nullptr);
        } else {
            vector<TreeNode *> left, right;
            for (int i = start; i <= end; i++) {
                left = genTrees(start, i - 1);
                right = genTrees(i + 1, end);
                for (auto lnode : left) {
                    for (auto rnode : right) {
                        TreeNode *root = new TreeNode(i);
                        root->left = lnode;
                        root->right = rnode;
                        res.push_back(root);
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution a;
    a.generateTrees(3);
    return 0;
}