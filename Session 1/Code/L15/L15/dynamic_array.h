#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include<iostream>
using namespace std;
template <typename T>
class dynamicarray {
    T * arr; 
    int size;
    int capacity;
//    const int constmember;
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
    // constructor!!!
    dynamicarray() : capacity(8), size(0) {
        cout << " Constructor called" << endl;
        arr = new T[8];
    }
    dynamicarray(int c) : capacity(c), size(0){
        cout << " Constructor called with one argument" << endl;
        arr = new T[c];
        capacity = c;
        size = 0;
    }
    dynamicarray(int c, const T & value) : capacity(c), size(c) {
        arr = new T[c];
        for(int i = 0; i <c;i++) {
            arr[i] = value;
        }
    }
    dynamicarray(const dynamicarray & b) : capacity(b.capacity), size(b.size){
        arr = new T[capacity];
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
        arr = new T[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = d.arr[i];
        }
    }
    int find(const T & el) const {
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
    void updateAtK(int K, const T & el) {
        if (K < 0 || K >= size) {
            return;
        }
        arr[K] = el;
        return;
    }
    void push_back(const T & el) {
        if (size == capacity) {
            expand();
        }
        arr[size] = el;
        size++;
    }
    dynamicarray & operator+=(const T & el) {
//        cout << this << endl;
        push_back(el);
        return *this;
    }
    dynamicarray & operator+=(const dynamicarray & b) {
        b.getSize();
        for (int i = 0; i < b.size; i++) {
            push_back(b[i]);
        }
        return *this;
    }
    dynamicarray operator+(const dynamicarray & b) {
        dynamicarray temp(*this);
        temp+=b;
        return temp;
    }
    T & operator[](int index) {
        return arr[index];
    }
    const T & operator[](int index) const{
        return arr[index];
    }
    int getSize() const {
        return size;
    }
    int getCapacity() const {
        return capacity;
    }
    template <typename V>
        friend void myFriendFunction(const dynamicarray<V> &);
    template<typename V>
        friend ostream & operator<<(ostream &, const dynamicarray<V> &);
};
template<typename T>
ostream & operator<<(ostream & obj, const dynamicarray<T> &d) {
    for(int i = 0; i < d.size; i++) {
        obj << d[i] <<" ";
    }
    return obj;
}
template <typename T>
void myFriendFunction(const dynamicarray<T> & d) {
   cout << d.size << endl;
   return;
}
#endif


