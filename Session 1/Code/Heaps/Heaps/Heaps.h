#ifndef HEAPS_H
#define HEAPS_H
#include<vector>
using namespace std;
template <typename T>
class MinHeap {
    vector<T> arr;
    void heapify() {
        for (int i = arr.size()/2; i >=1; i--) {
            percolateDown(i);
        }
    }
    void percolateDown(int i) {
        while (2 * i < arr.size()) {
            int small = 2*i;
            if (2 * i + 1 < arr.size() && arr[2*i+1] < arr[2*i]) {
                small = 2*i+1;
            }
            if (arr[small] < arr[i]) {
                swap(arr[small], arr[i]);
                i = small;
            } else {
                break;
            }
        }
    }
    public:
    MinHeap() {
        arr.resize(1);
    }
    MinHeap(const vector<T> & v ) {
        arr.resize(1);
        for(int i = 0; i < v.size(); i++) {
            arr.push_back(v[i]);
        }
        heapify();
    }
    void insert(const T & el) {
        arr.push_back(el);
        for (int i = arr.size() - 1; i > 1 && arr[i/2] > arr[i]; i/=2) {
            swap(arr[i], arr[i/2]);
        }
    }
    void removeMin() {
        if (isEmpty()) {
            throw " Heap is Empty!!";
        }
        T el = arr.back();
        arr.pop_back();
        if (isEmpty()) {
            return;
        }
        arr[1] = el;
        percolateDown(1);
    }
    const T & getMin() const {
        if (isEmpty()) {
            throw " Heap is Empty!!";
        }
        return arr[1];
    }
    T & getMin()  {
        if (isEmpty()) {
            throw " Heap is Empty!!";
        }
        return arr[1];
    }
    int size() const {
        return arr.size() -1 ;
    }
    bool isEmpty() const {
        return size() == 0;
    }


};
#endif
