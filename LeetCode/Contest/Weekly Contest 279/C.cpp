#include <bits/stdc++.h>
using namespace std;

class Bitset {
    string s[2];
    int cnt, now;

   public:
    Bitset(int size) {
        s[0] = s[1] = "";
        now = cnt = 0;
        for (int i = 0; i < size; i++) {
            s[now] += '0';
            s[now ^ 1] += '1';
        }
    }

    void fix(int idx) {
        if (s[now][idx] == '1') return;
        swap(s[now][idx], s[now ^ 1][idx]);
        cnt++;
    }

    void unfix(int idx) {
        if (s[now][idx] == '0') return;
        swap(s[now][idx], s[now ^ 1][idx]);
        cnt--;
    }

    void flip() {
        now = now ^ 1;
        cnt = s[0].size() - cnt;
    }

    bool all() { return cnt == s[0].size(); }

    bool one() { return cnt != 0; }

    int count() { return cnt; }

    string toString() { return s[now]; }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */