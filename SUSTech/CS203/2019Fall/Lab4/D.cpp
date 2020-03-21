#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e4 + 5;

struct person {
    int val, id;
    person *prev, *next;
    person(int val, int id) : val(val), id(id), prev(nullptr), next(nullptr) {}
};

int T, n, m;
person *head, *tail;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n >> m;
        head = nullptr, tail = nullptr;
        for (int i = 1, val; i <= n; ++i) {
            cin >> val;
            person *t = new person(val, i);
            if (!head) head = t;
            if (tail) {
                tail->next = t;
                t->prev = tail;
            }
            tail = t;
        }
        tail->next = head;
        head->prev = tail;
        while (n) {
            head = head->prev;
            m %= n;
            while (m--) head = head->next;
            m = head->val;
            head->prev->next = head->next;
            head->next->prev = head->prev;
            --n;
        }
        cout << head->id << '\n';
    }

    return 0;
}