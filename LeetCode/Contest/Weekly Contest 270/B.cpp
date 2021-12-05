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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *ite = head;
        int cnt = 0;
        while (ite) {
            cnt++;
            ite = ite->next;
        }
        if (cnt == 1) return nullptr;
        int num = cnt / 2, id = 0;
        ite = head;
        while (id != num - 1) {
            id++;
            ite = ite->next;
        }
        ite->next = ite->next->next;
        return head;
    }
};