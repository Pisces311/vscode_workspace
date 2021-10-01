#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode *cut(ListNode *head, int num) {
        ListNode *prev = head;
        if (head) head = head->next;
        int cur = 1;
        while (cur < num) {
            prev = head;
            head = head->next;
            cur++;
        }
        if (prev) prev->next = nullptr;
        return head;
    }

   public:
    vector<ListNode *> splitListToParts(ListNode *head, int k) {
        ListNode *dummy = new ListNode(0, head);
        int cnt = 0;
        while (dummy->next) {
            dummy = dummy->next;
            cnt++;
        }
        int chunk = cnt / k, more = cnt % k;
        vector<ListNode *> ret;
        for (int i = 0; i < more; i++) {
            ret.push_back(head);
            head = cut(head, chunk + 1);
        }
        for (int i = 0; i < k - more; i++) {
            ret.push_back(head);
            head = cut(head, chunk);
        }
        return ret;
    }
};