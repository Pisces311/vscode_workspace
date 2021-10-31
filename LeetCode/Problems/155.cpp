#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<int> stk, minStk;

   public:
    MinStack() {}

    void push(int val) {
        stk.push(val);
        if (minStk.empty())
            minStk.push(val);
        else
            minStk.push(min(val, minStk.top()));
    }

    void pop() {
        stk.pop();
        minStk.pop();
    }

    int top() { return stk.top(); }

    int getMin() { return minStk.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */