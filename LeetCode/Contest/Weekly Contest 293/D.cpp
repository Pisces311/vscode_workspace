#include <bits/stdc++.h>
using namespace std;

struct node {
    int l, r, len;
    node(int l, int r) : l(l), r(r) { len = r - l + 1; }
    bool operator<(const node& a) const { return l < a.l; }
};

class CountIntervals {
    set<node> st;
    int ans;

   public:
    CountIntervals() {
        st.clear();
        ans = 0;
    }

    void add(int left, int right) {
        node cur(left, right);
        auto next = st.lower_bound(cur);
        if (next != st.begin()) {
            auto prev = --next;
            if (prev->r >= cur.l) {
                node x(prev->l, max(prev->r, cur.r));
                ans -= prev->len;
                st.erase(prev);
                cur = x;
            }
        }
        while (true) {
            auto next = st.lower_bound(cur);
            if (next != st.end() && cur.r >= next->l) {
                node x(cur.l, max(cur.r, next->r));
                ans -= next->len;
                st.erase(next);
                cur = x;
            } else
                break;
        }
        st.insert(cur);
        ans += cur.len;
    }

    int count() { return ans; }
};