#include <bits/stdc++.h>
using namespace std;

struct query {
    int id, t;
};

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (int i = 0; i < a.size(); i++) add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
        return ret;
    }

    int sum(int l, int r) { return sum(r) - sum(l - 1); }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta;
    }
};


class Solution {
   public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers,
                                 vector<int>& persons) {
        vector<int> val;
        for (vector<int>& i : flowers) {
            val.push_back(i[0]);
            val.push_back(i[1]);
        }
        for (int i : persons) val.push_back(i);
        sort(val.begin(), val.end());
        map<int, int> ma;
        int cnt = 1;
        for (int i = 0; i < val.size(); i++) {
            if (i == 0 || val[i] != val[i - 1]) ma[val[i]] = cnt++;
        }
        for (vector<int>& i : flowers) {
            i[0] = ma[i[0]];
            i[1] = ma[i[1]];
        }
        for (int& i : persons) i = ma[i];

        int n = persons.size();
        sort(flowers.begin(), flowers.end(),
             [&](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
        vector<query> q(n);
        for (int i = 0; i < n; i++) {
            q[i] = {i, persons[i]};
        }
        sort(q.begin(), q.end(), [&](query& a, query& b) { return a.t < b.t; });

        int j = 0;
        vector<int> ans(n);
        FenwickTree ft(2e5 + 5);
        for (int i = 0; i < n; i++) {
            while (j < flowers.size() && flowers[j][0] <= q[i].t) {
                ft.add(flowers[j][1], 1);
                j++;
            }
            ans[q[i].id] = ft.sum(q[i].t, 2e5);
        }
        return ans;
    }
};