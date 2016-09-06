#ifndef GENERIC_TREE_H
#define GENERIC_TREE_H
#include<vector>
#include<queue>
using namespace std;
template <typename T>
class GenericTreeNode {
    T data;
    vector<GenericTreeNode *> children;
    GenericTreeNode * parent;
    public:
    GenericTreeNode() : parent(NULL){}
    GenericTreeNode(const T & d) : parent(NULL), data(d) {}
    const T & getData() const {
        return data;
    }

    template<typename V>
        friend class GenericTree;
};
template<typename T>
class GenericTree {
    GenericTreeNode<T> * root;
    static void printPreOrderHelper(GenericTreeNode<T> * root) {
        if (root == NULL) {
            return;
        }
        cout << root->data << " ";
        for(int i = 0; i < root->children.size(); i++) {
            printPreOrderHelper(root->children[i]);
        }
        return;
    }
    public:
    GenericTree() : root(0) {}
    void printPreOrder() {
        printPreOrderHelper(root);
    }
    void createTree() {
        if (root != NULL) {
            throw " tree already exists";
        }
        T el;
        cout << "Enter data for root node";
        cin >> el;
        root = new GenericTreeNode<T>(el);
        queue<GenericTreeNode<T> * > Q;
        Q.push(root);
        while(!Q.empty()) {
            int count;
            GenericTreeNode<T> * temp = Q.front();
            Q.pop();
            cout << " Enter children count for node with data: " << temp->data << " ";
            cin >>count;
            for (int i =0; i < count; i++) {
                cout << " Enter data for " << i << " child  ";
                cin >> el;
                GenericTreeNode<T> * child = new GenericTreeNode<T>(el);
                child->parent = temp;
                temp->children.push_back(child);
                Q.push(child);
            }
        }
    }
};
#endif
