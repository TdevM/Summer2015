#include<iostream>
#include<vector>
#include"Heaps.h"
using namespace std;
int main() {
    MinHeap <int> H;
    int n;
    for(int i = 0; i < 10; i++) {
        cout << "Enter a new number";
        cin >> n;
        H.insert(n);
        cout << "Minimum till now is " << H.getMin() << endl;
    }
    cout << H.size() << endl;
    for(int i = 0; i < 10; i++) {
        cout << H.getMin() << " ";
        H.removeMin();
    }
    cout << endl << H.size() << endl;

    // using a vector to create heap
    int arr[] = { 3,4,5,2,6,8,-10,34,21,43,11,2,4};
    vector<int> V(arr, arr + sizeof(arr)/sizeof(int) );
    cout << V.size() << endl;
    MinHeap <int> H1(V);
    while(!H1.isEmpty()) {
        cout << H1.getMin() << " ";
        H1.removeMin();
    }


    return 0;
}

