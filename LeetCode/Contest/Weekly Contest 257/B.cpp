#include <bits/stdc++.h>
using namespace std;

struct node {
    int a, d;
    bool operator<(const node& rhs) const {
        return a == rhs.a ? d < rhs.d : a < rhs.a;
    }
};

class Solution {
   public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        vector<vector<int>> num(100005);
        for (int i = 0; i < properties.size(); i++) {
            num[properties[i][0]].push_back(properties[i][1]);
        }
        int ma = -1;
        int ans = 0;
        for (int i = 100000; i >= 1; i--) {
            sort(num[i].begin(), num[i].end());
            if (!num[i].empty()) {
                for (auto j : num[i]) {
                    if (j < ma) ans++;
                }
                ma = max(ma, num[i][num[i].size() - 1]);
            }
        }
        return ans;
    }
};

int main() {
    Solution a;
    vector<vector<int>> v = {{7, 9}, {10, 7}, {6, 9}, {10, 4}, {7, 5}, {7, 10}};
    cout << a.numberOfWeakCharacters(v) << endl;
    return 0;
}