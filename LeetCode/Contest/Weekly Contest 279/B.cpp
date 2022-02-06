#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long smallestNumber(long long num) {
        vector<int> dig;
        long long ret = 0;
        if (num > 0) {
            while (num) {
                dig.push_back(num % 10);
                num /= 10;
            }
            sort(dig.begin(), dig.end());
            for (int i = 0; i < dig.size(); i++) {
                if (dig[i] != 0) {
                    ret += dig[i];
                    for (int j = 0; j < dig.size(); j++) {
                        if (j != i) {
                            ret *= 10;
                            ret += dig[j];
                        }
                    }
                    return ret;
                }
            }
        } else if (num < 0) {
            num *= -1;
            while (num) {
                dig.push_back(num % 10);
                num /= 10;
            }
            sort(dig.begin(), dig.end(), [](int a, int b) { return a > b; });
            ret = dig[0];
            for (int i = 1; i < dig.size(); i++) {
                ret *= 10;
                ret += dig[i];
            }
            return -ret;
        }
        return 0;
    }
};