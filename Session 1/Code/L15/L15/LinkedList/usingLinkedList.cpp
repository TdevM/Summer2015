#include<iostream>
#include "LL.h"
using namespace std;
int main() {
    Node<char> N;
    LinkedList<int> L;
    for(int i = 0; i < 10;i++) {
        L.append('A');
    }
    LinkedList<int> L1 = L;
    L.prepend(45);
    L.prepend(34);
    cout << L << endl;
    return 0;
}
