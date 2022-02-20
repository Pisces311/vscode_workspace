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
    ListNode* mergeNodes(ListNode* head) {
        vector<int> v;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        head = new ListNode(0);
        ListNode* cur = head;
        int tot = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == 0) {
                if (tot != 0) {
                    ListNode* tmp = new ListNode(tot);
                    cur->next = tmp;
                    cur = tmp;
                    tot = 0;
                    if (!head) head = cur;
                }
            } else
                tot += v[i];
        }
        return head->next;
    }
};