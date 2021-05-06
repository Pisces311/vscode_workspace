#ifndef STACK_H_
#define STACK_H_
typedef unsigned long Item;

class Stack {
    public:
    enum { MAX = 10 };
    Item *pitems;
    int size;
    int top;

   public:
    Stack(int n = MAX);
    Stack(const Stack &st);
    ~Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item &item);
    bool pop(Item &item);
    Stack &operator=(const Stack &st);
};
#endif