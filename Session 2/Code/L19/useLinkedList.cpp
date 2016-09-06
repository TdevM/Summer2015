#include<iostream>
#include"LinkedList.h"
using namespace std;
int main() {
    SingleLinkedList<int> L1;
    SingleLinkedList<char> L2;
    for (int i =65; i < 90; i++) {
        L1.insertAtTheEnd(i);
        L2.insertAtTheEnd(i);
    }
    cout << L1 << endl;
    cout << L2 << endl;
    cout << ++L1 << endl;
    cout << ++L2 << endl;
    return 0;
}
