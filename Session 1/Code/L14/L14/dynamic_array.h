#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include<iostream>
using namespace std;
class dynamicarray {
    int * arr; 
    int size;
    int capacity;
//    const int constmember;
    void expand() {
        capacity *=2;
        int * temp = new int[capacity];
        for(int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }
        delete [] arr;
        arr = temp;
    }
    public:
    // constructor!!!
    dynamicarray() : capacity(8), size(0) {
        cout << " Constructor called" << endl;
        arr = new int[8];
    }
    dynamicarray(int c) : capacity(c), size(0){
        cout << " Constructor called with one argument" << endl;
        arr = new int[c];
        capacity = c;
        size = 0;
    }
    dynamicarray(int c, int value) : capacity(c), size(c) {
        arr = new int[c];
        for(int i = 0; i <c;i++) {
            arr[i] = value;
        }
    }
    dynamicarray(const dynamicarray & b) : capacity(b.capacity), size(b.size){
        arr = new int[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = b.arr[i];
        }
    }
    ~dynamicarray() {
        cout << "Destructor is called" << endl;
        delete [] arr;
    }
    void operator=(const dynamicarray & d) {
        delete [] arr;
        capacity = d.capacity;
        size = d.size;
        arr = new int[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = d.arr[i];
        }
    }
    int get(int index) {
        return arr[index];
    }
    int find(int el) {
        int pos = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == el) {
                pos = i;
                break;
            }
        }
        return pos;
    }
    void deleteAtK(int k) {
        if (k < 0 || k >= size) {
            return;
        }
        for (int i = k+1; i < size; i++) {
            arr[i-1] = arr[i];
        }
        size--;
    }
    void pop_back() {
        if (size == 0) {
            return;
        } 
        size--;
    }
    void updateAtK(int K, int el) {
        if (K < 0 || K >= size) {
            return;
        }
        arr[K] = el;
        return;
    }
    void push_back(int el) {
        if (size == capacity) {
            expand();
        }
        arr[size] = el;
        size++;
    }
    dynamicarray & operator+=(int el) {
//        cout << this << endl;
        push_back(el);
        return *this;
    }
    dynamicarray & operator+=(const dynamicarray & b) {
        b.getSize();
        for (int i = 0; i < b.size; i++) {
            push_back(b.get(i));
        }
        return *this;
    }
    dynamicarray operator+(const dynamicarray & b) {
        dynamicarray temp(*this);
        temp+=b;
        return temp;
    }
    int & operator[](int index) {
        return arr[index];
    }
    int getSize() {
        return size;
    }
    int getCapacity() {
        return capacity;
    }
};
#endif


