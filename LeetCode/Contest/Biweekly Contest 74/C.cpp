#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double sum = accumulate(nums.begin(), nums.end(), 0.0);
        for (double i : nums) pq.push(i);
        double cur = sum;
        int cnt = 0;
        while (cur > sum / 2) {
            double top = pq.top();
            pq.pop();
            cur -= top - top / 2;
            top /= 2;
            pq.push(top);
            cnt++;
        }
        return cnt;
    }
};