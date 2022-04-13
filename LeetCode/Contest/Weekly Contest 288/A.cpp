#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int largestInteger(int num) {
        vector<int> odd, even;
        int tmp = num;
        while (tmp) {
            int digit = tmp % 10;
            if (digit & 1)
                odd.push_back(digit);
            else
                even.push_back(digit);
            tmp /= 10;
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        int i = odd.size() - 1, j = even.size() - 1;
        string str = to_string(num);
        int ret = 0;
        for (char ch : str) {
            int digit = ch - '0';
            ret *= 10;
            if (digit & 1) {
                ret += odd[i];
                i--;
            } else {
                ret += even[j];
                j--;
            }
        }
        return ret;
    }
};