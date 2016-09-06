#ifndef QUEUE_AS_DYNAMIC_ARRAY_H
#define QUEUE_AS_DYNAMIC_ARRAY_H
#include<iostream>
using namespace std;
template<typename T>
class QueueAsDA {
    T * arr;
    int front; 
    int rear; 
    int capacity;
    void copyAs(T * copyarr, int f, int r, int n) {
        if (f == -1) {
            front = -1;
            rear = 0;
            return;
        }
        int k = 0;
        if (f < r) {
            for(int i = f; i < r; i++) {
                arr[k] = copyarr[i];
                k++;
            }
        } else {
            for (int i = f; i < n; i++) {
                arr[k] = copyarr[i];
                k++;
            }
            for (int i = 0; i < r;i++) {
                arr[k] = copyarr[i];
                k++;
            }
        }
        front = 0;
        rear = k;
    }
    void expand() {
        cout << "Expand Called" << endl;
        T * temp = new T[2*capacity];
        T * temp2 = arr;
        arr = temp;
        copyAs(temp2, front, rear, capacity);
        capacity = 2*capacity;
        delete temp2;
    }
    public:
    QueueAsDA() : front(-1), rear(0), capacity(8) {
        arr = new T[capacity];
    }
    ~QueueAsDA() {
        delete arr;
    }
    QueueAsDA(const  QueueAsDA & Q) {
        arr = new T[Q.capacity];
        capacity = Q.capacity;
        copyAs(Q.arr, Q.front, Q.rear,Q.capacity);
    }
    QueueAsDA & operator=(const QueueAsDA & Q) {
        delete arr;
        arr = new T[Q.capacity];
        capacity = Q.capacity;
        copyAs(Q.arr, Q.front, Q.rear,Q.capacity);
    }
    void enqueue(const T & el) {
        if (rear == front) {
            expand();
        }
        arr[rear] = el;
        // rear = (rear+1)%capacity;
        rear = rear + 1;
        if (rear == capacity) {
            rear = 0;
        }
        if (front == -1) {
            front = 0;
        }
    }
    void dequeue() {
        if (isEmpty()) {
            throw " Queue is Empty";
        }
        front = (front + 1)%capacity;
        if (front == rear) {
            front = -1;
            rear = 0;
        }
    }
    T & getFront() {
        if (isEmpty()) {
            throw " Queue is Empty";
        }
        return arr[front];
    }
    const T & getFront() const {
        if (isEmpty()) {
            throw " Queue is Empty";
        }
        return arr[front];
    }
    bool isEmpty() {
        return front == -1;
    }
};
#endif
