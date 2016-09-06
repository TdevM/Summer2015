#include<iostream>
#include "LL.h"
using namespace std;
int main() {
    LinkedList<int> L;
    for(int i = 10; i > 0 ;i--) {
        L.append(i*i);
    }
    cout << L << endl;
    L.convertAnBn();
    cout << L << endl;
    L.selectionSort();
    cout << L << endl;
    return 0;
}
