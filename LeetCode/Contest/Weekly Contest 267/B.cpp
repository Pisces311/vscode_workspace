#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<int> val;
        ListNode* tmp = head;
        while (tmp) {
            val.push_back(tmp->val);
            tmp = tmp->next;
        }
        int n = val.size();
        int cur = 1, l = 0, r = 0;
        while (true) {
            r = min(l + cur, n);
            if ((r - l) % 2 == 0) reverse(val.begin() + l, val.begin() + r);
            l = r;
            if (l >= n) break;
            cur++;
        }
        tmp = head;
        int i = 0;
        while (tmp) {
            tmp->val = val[i];
            tmp = tmp->next;
            i++;
        }
        return head;
    }
};