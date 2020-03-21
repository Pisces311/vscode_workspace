#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

struct node {
    char val;
    node *prev, *next;
    node(char val) : val(val), prev(nullptr), next(nullptr) {}
};

int T, n;
char op;
node *head, *cur;

void insert(char ch) {
    node *t = new node(op);
    if (cur->prev) {
        cur->prev->next = t;
        t->prev = cur->prev;
        cur->prev = t;
        t->next = cur;
    } else {
        cur->prev = t;
        t->next = cur;
        head = t;
    }
}

void del() {
    if (cur->val == '\n') return;
    if (cur->prev) {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
    } else {
        cur->next->prev = NULL;
        head = cur->next;
    }
    cur = cur->next;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n;
        node *EOL = new node('\n');
        head = EOL, cur = EOL;
        while (n--) {
            cin >> op;
            if (op >= '0' && op <= '9')
                insert(op);
            else {
                if (op == 'r' && n) {
                    cin >> op;
                    if (cur->val == '\n') {
                        insert(op);
                        cur = cur->prev;
                    } else
                        cur->val = op;
                    --n;
                }
                if (op == 'I') cur = head;
                if (op == 'H')
                    if (cur->prev) cur = cur->prev;
                if (op == 'L')
                    if (cur->next) cur = cur->next;
                if (op == 'x') del();
            }
        }
        while (head->val != '\n') {
            cout << head->val;
            head = head->next;
        }
        cout << '\n';
    }

    return 0;
}