#include <bits/stdc++.h>
using namespace std;

struct node {
    bool locked;
    int user;
    int fa;
    vector<int> son;
};

class LockingTree {
   public:
    vector<node> tree;

    LockingTree(vector<int>& parent) {
        tree.resize(parent.size());
        for (int i = 0; i < tree.size(); i++) {
            tree[i].son.clear();
        }
        for (int i = 0; i < parent.size(); i++) {
            tree[i].fa = parent[i];
            if (parent[i] != -1) tree[parent[i]].son.push_back(i);
            tree[i].locked = false;
            tree[i].user = -1;
        }
    }

    bool lock(int num, int user) {
        if (tree[num].locked) return false;
        tree[num].locked = true;
        tree[num].user = user;
        return true;
    }

    bool unlock(int num, int user) {
        if (tree[num].locked && tree[num].user == user) {
            tree[num].locked = false;
            tree[num].user = -1;
            return true;
        }
        return false;
    }

    bool descendant(int num) {
        if (tree[num].locked) return true;
        for (int i : tree[num].son) {
            if (descendant(i)) return true;
        }
        return false;
    }

    bool ancestor(int num) {
        if (num == -1) return false;
        if (tree[num].locked) return true;
        return ancestor(tree[num].fa);
    }

    void unlock_all(int num) {
        tree[num].locked = false;
        tree[num].user = -1;
        for (int i = 0; i < tree[num].son.size(); i++) {
            unlock_all(tree[num].son[i]);
        }
    }

    bool upgrade(int num, int user) {
        if (!tree[num].son.size()) return false;
        bool locked_son = false;
        for (int i = 0; i < tree[num].son.size(); i++)
            locked_son = locked_son || descendant(tree[num].son[i]);
        if (!locked_son) return false;
        if (ancestor(num)) return false;
        tree[num].locked = true;
        tree[num].user = user;
        for (int i = 0; i < tree[num].son.size(); i++) {
            unlock_all(tree[num].son[i]);
        }
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */

int main() {
    vector<int> pa = {-1, 0, 0, 1, 1, 2, 2};
    LockingTree* obj = new LockingTree(pa);
    bool param_1 = obj->lock(2, 2);
    bool param_2 = obj->unlock(2, 3);
    bool param_3 = obj->unlock(2, 2);
    bool param_4 = obj->lock(4, 5);
    bool param_5 = obj->upgrade(0, 1);
    bool param_6 = obj->lock(0, 1);
    if (param_1 && !param_2 && param_3 && param_4 && param_5 && !param_6)
        cout << "Pass" << endl;
    return 0;
}