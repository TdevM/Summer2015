#ifndef STACKS_AS_ARRAY_H
#define STACKS_AS_ARRAY_H
#include<iostream>
using namespace std;
#define MAX_CAPACITY 1000
template <typename T>
class Stack {
    T arr[MAX_CAPACITY];
    int top;
    public:
    Stack() : top(0) {}
    void push(const T & el) {
        if (top == MAX_CAPACITY) {
            cout << " No space!!" << endl;
            return;
        }
        arr[top] = el;
        top++;
    }
    bool isEmpty() const {
        return top == 0;
    }
    int size() const {
        return top;
    }
    void clear() {
        top = 0;
        return;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack is Empty!!" << endl;
            return;
        }
        top--;
    }
    T & getTop() {
        return arr[top - 1];
    }
    const T & getTop() const {
        return arr[top - 1];
    }
};
#endif
