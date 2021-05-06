#include "stack.h"

#include <algorithm>
using namespace std;

Stack::Stack(int n) {
    size = n;
    top = 0;
    pitems = new Item[size];
}

Stack::Stack(const Stack &st) {
    size = st.size;
    top = st.top;
    pitems = new Item[size];
    copy(st.pitems, st.pitems + size, pitems);
}

Stack::~Stack() { delete pitems; }

bool Stack::isempty() const { return top == 0; }

bool Stack::isfull() const { return top == size - 1; }

bool Stack::push(const Item &item) {
    if (this->isfull()) return false;
    pitems[top++] = item;
    return true;
}

bool Stack::pop(Item &item) {
    if (this->isempty()) return false;
    item = pitems[--top];
    return true;
}

Stack &Stack::operator=(const Stack &st) {
    if (this == &st) return *this;
    delete pitems;
    size = st.size;
    top = st.top;
    pitems = new Item[size];
    copy(st.pitems, st.pitems + size, pitems);
    return *this;
}