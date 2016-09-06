#ifndef STACK_AS_DYNAMIC_ARRAY_H
#define STACK_AS_DYNAMIC_ARRAY_H
#include<iostream>
#include<exception>
using namespace std;
class StackEmptyException : public exception {
    public:
        virtual char const * what() const throw () { return "Stack is Empty";}
};
template <typename T>
class StackAsDA {
    T * arr; 
    int size;
    int capacity;
    void expand() {
        capacity *=2;
        T * temp = new T[capacity];
        for(int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }
        delete [] arr;
        arr = temp;
    }
    public:
    StackAsDA() : capacity(8), size(0) {
        arr = new T[8];
    }
    StackAsDA(int c) : capacity(c), size(0){
        arr = new T[c];
        capacity = c;
        size = 0;
    }
    StackAsDA(const StackAsDA & b) : capacity(b.capacity), size(b.size){
        arr = new T[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = b.arr[i];
        }
    }
    ~StackAsDA() {
        delete [] arr;
    }
    void operator=(const StackAsDA & d) {
        delete [] arr;
        capacity = d.capacity;
        size = d.size;
        arr = new T[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = d.arr[i];
        }
    }
    void pop() {
        if (size == 0) {
            throw StackEmptyException();
        }
        size--;
    }
    void push(const T & el) {
        if (size == capacity) {
            expand();
        }
        arr[size] = el;
        size++;
    }
    bool isEmpty() {
        return size == 0;
    }
    const T & top() const {
        return arr[size-1];
    }
    T & top() {
        if (size == 0) {
            StackEmptyException ex;
            throw ex;
        }
        return arr[size-1];
    }
};
#endif


