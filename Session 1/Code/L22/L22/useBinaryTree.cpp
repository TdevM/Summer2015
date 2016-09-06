#include<iostream>
#include"BinaryTree.h"
using namespace std;
int main() {
    BinaryTree<int> T1;
    T1.createRecursive();
    cout << " Pre Order Traversal is : ";
    T1.printPreOrder();
    cout << " Post Order Traversal is : ";
    T1.printPostOrder();
    cout << " In Order Traversal is : ";
    T1.printInOrder();
    cout << " Height of the tree is : " << T1.height() << endl;
    cout << " Diameter of the tree is : : " << T1.diameter() << endl;
    BinaryTree<int> T2;
    T2.createRecursive();
    cout << " Pre Order Traversal of T2 is : ";
    T2.printPreOrder();
    cout << " Post Order Traversal of T2 is : ";
    T2.printPostOrder();
    cout << " In Order Traversal of T2 is : ";
    T2.printInOrder();
    cout << "Making T2 = T1" << endl;
    T2 = T1;
    cout << " In Order Traversal of T2 is : ";
    T2.printInOrder();
    cout << "Clearing T1 " << endl;
    T1.clear();
    cout << " In Order Traversal of T2 is : ";
    T2.printInOrder();
    cout << " In Order Traversal of T1 is : ";
    T1.printInOrder();

    BinaryTree<int> T3 = T2;
    cout << "In Order Traversal of T3 is: ";
    T3.printInOrder();
    
    vector<int> Pre;
    vector<int> In;
    int N, el;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> el;
        Pre.push_back(el);
    }
    for (int i = 0; i < N; i++) {
        cin >> el;
        In.push_back(el);
    }
    BinaryTree<int> T4(Pre, In);
    cout << "Post Order is : ";
    T4.printPostOrder();
    return 0;
}
