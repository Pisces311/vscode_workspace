#include <bits/stdc++.h>
using namespace std;

class KMP {
   public:
    string s, t;
    vector<int> next;

    KMP(string s, string t) : s(s), t(t), next(vector<int>(t.size())) { getNext(); }

    void getNext() {
        for (int q = 1, k = 0; q < t.size(); q++) {
            while (k > 0 && t[q] != t[k]) k = next[k - 1];
            if (t[q] == t[k]) k++;
            next[q] = k;
        }
    }

    // @return the start positions of all occurrences of t in s
    vector<int> find() {
        vector<int> pos;
        for (int i = 0, j = 0; i < s.size(); i++) {
            while (j > 0 && t[j] != s[i]) j = next[j - 1];
            if (t[j] == s[i]) j++;
            if (j == t.size()) {
                pos.push_back(i - t.size() + 1);
                j = next[j - 1];
            }
        }
        return pos;
    }
};