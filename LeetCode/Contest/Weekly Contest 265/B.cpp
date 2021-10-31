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
   public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head) {
        int id = 1;
        vector<int> critical;
        while (head != nullptr) {
            if (head->next && head->next->next) {
                if (head->next->val < head->val &&
                    head->next->val < head->next->next->val)
                    critical.push_back(id + 1);
                if (head->next->val > head->val &&
                    head->next->val > head->next->next->val)
                    critical.push_back(id + 1);
            }
            head = head->next;
            id++;
        }
        if (critical.size() < 2) return {-1, -1};
        int Min = INT_MAX, Max = critical.back() - critical.front();
        for (int i = 1; i < critical.size(); i++) {
            Min = min(Min, critical[i] - critical[i - 1]);
        }
        return {Min, Max};
    }
};