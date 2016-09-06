#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include<vector>
#include<queue>
#include<limits>
using namespace std;
template <typename T>
class BinaryTreeNode {
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    public:
    BinaryTreeNode(): left(NULL), right(NULL){}
    BinaryTreeNode(const T & d) : data(d) , left(NULL), right(NULL){}
    const T & getData() const {
        return data;
    }

    template<typename V>
        friend class BinaryTree;
};
template<typename T>
class BinaryTree {
    BinaryTreeNode<T> * root;
    public:
    BinaryTree() : root(NULL) {}
    BinaryTree(const vector<T> &pre, const vector<T> & in) : root(0){
        if (pre.size() != in.size()) {
            throw "Improper data";
        }
        if (pre.size() == 0) {
            return;
        }
        root = createFromPreAndIn(pre, in, 0, pre.size() - 1, 0, in.size() - 1);
    }
    ~BinaryTree() { clear(); }
    BinaryTree(const BinaryTree & T1) : root(NULL) {
        if(T1.root == NULL) { return;}
        root = copyas(T1.root);
    }
    BinaryTree & operator=(const BinaryTree & T1) {
        clear();
        root = copyas(T1.root);
        return *this;
    }
    bool isEmpty() { return root == NULL; }
    void clear() {
        clearHelper(root);
        root = NULL;
    }
    void createRecursive() {
        if (root) { throw "Tree already Exists";}
        T el;
        cout << "Enter data for root";
        cin >> el;
        root = new BinaryTreeNode<T>(el);
        createRecurisveHelper(root);
    }
    void copyLeftNodes() {
        if (!root) {
            return;
        }
        root = copyLeftNodesHelper(root, 0);
    }
    void printPreOrder() {
        printPreOrderHelper(root);
        cout << endl;
        return;
    }
    void printPostOrder() {
        printPostOrderHelper(root);
        cout << endl;
        return;
    }
    void printInOrder() {
        printInOrderHelper(root);
        cout << endl;
        return;
    }
    int height() {
        return heightHelper(root);
    }
    int diameter() {
        pair<int, int> ans = diameterHelper(root);
        return ans.first;
    }
    bool checkIfBST() const {
        T min_value = numeric_limits<T>::min();
        T max_value = numeric_limits<T>::max();
        return checkIfBSThelper(root, min_value, max_value);
    }
    private:
    static bool checkIfBSThelper(BinaryTreeNode<T>* root, T min, T max) {
        if(!root) return true;
        if (root->data < min || root->data > max) return false;
        return checkIfBSThelper(root->left, min, root->data) && checkIfBSThelper(root->right, root->data, max);

    }
    static BinaryTreeNode<T> * removeAllNodesWithPathSumLessThanK( BinaryTreeNode<T> * root, T sum, T k) {
        if (!root) return NULL;
        T current_sum = sum+root->data;
        if (!root->left && !root->right) {
            if (current_sum >= k) {
                return root;
            } else {
                delete root;
                return NULL;
            }
        }
        root->left = removeAllNodesWithPathSumLessThanK(root->left, current_sum, k);
        root->right = removeAllNodesWithPathSumLessThanK(root->right, current_sum, k);
        if ((root->left || root->right) || current_sum >= k) {
            return root;
        } else {
            delete root;
            return NULL;
        }
    }

    static pair<int, int> diameterHelper(BinaryTreeNode<T> * root) {
        pair<int, int> P(0,0);
        if (root == NULL) {
            return P;
        }
        pair<int, int> l,r;
        l = diameterHelper(root->left);
        r = diameterHelper(root->right);
        P.second = max(l.second, r.second)+1;
        P.first = max(max(l.first, r.first), l.second + r.second +1);
        return P;
    }
    static int heightHelper(BinaryTreeNode<T> * root) {
        if (root == NULL) {
            return 0;
        }
        return max(heightHelper(root->left), heightHelper(root->right)) + 1;
    }
    static void printPreOrderHelper(BinaryTreeNode<T> * root) {
        if (!root) return;
        cout << root->data << " ";
        printPreOrderHelper(root->left);
        printPreOrderHelper(root->right);
    }
    static void printPostOrderHelper(BinaryTreeNode<T> * root) {
        if (!root) return;
        printPostOrderHelper(root->left);
        printPostOrderHelper(root->right);
        cout << root->data << " ";
    }
    static void printInOrderHelper(BinaryTreeNode<T> * root) {
        if (!root) return;
        printInOrderHelper(root->left);
        cout << root->data << " ";
        printInOrderHelper(root->right);
    }
    static int findInInorder(const vector<T> &in, int start, int end, int el) {
        if (start == end) {
            return end;
        }
        for(int i =start; i <=end;i++) {
            if(in[i] == el) {
                return i;
            }
        }
        return -1;
    }

    static BinaryTreeNode<T>* createFromPreAndIn(const vector<T> &pre, const vector<T> &in,
            int prestart, int preend, int instart, int inend) {
        if (prestart > preend) {
            return NULL;
        }
        BinaryTreeNode<T> *root = new BinaryTreeNode<T>(pre[prestart]);
        int pos = findInInorder(in, instart, inend, pre[prestart]);
        int leftpreend = prestart+pos-instart;
        root->left = createFromPreAndIn(pre, in, prestart+1 , leftpreend , instart, pos-1);
        root->right = createFromPreAndIn(pre, in, leftpreend+1, preend, pos+1, inend);
        return root;
    }
    static BinaryTreeNode<T> * copyLeftNodesHelper(BinaryTreeNode<T> *root, bool flag) {
        if (root == NULL) {
            return NULL;
        }
        root->left = copyLeftNodesHelper(root->left, 1);
        root->right = copyLeftNodesHelper(root->right, 0);
        if (flag == 1) {
            BinaryTreeNode<T> * temp = new BinaryTreeNode<T>(root->data);
            temp->left = root;
            return temp;
        }else {
            return root;
        }
    }
    static BinaryTreeNode<T>* copyas( BinaryTreeNode<T> * fromroot) {
        if (fromroot == NULL) {
            return NULL;
        }
        BinaryTreeNode<T> * root = new BinaryTreeNode<T>(fromroot->data);
        root->left = copyas(fromroot->left);
        root->right = copyas(fromroot->right);
        return root;
    }
    static void clearHelper(BinaryTreeNode<T> * root) {
        if (root == NULL) return;
        clearHelper(root->left);
        clearHelper(root->right);
        delete root;
        return;
    }
    static void createRecurisveHelper(BinaryTreeNode<T> * root) {
        if (root == NULL) {
            return;
        }
        char ch;
        T el;
        cout << root->data <<" has left? (y/n)";
        cin >> ch;
        if (ch == 'Y' || ch == 'y') {
            cout << "Enter data for left  ";
            cin >> el;
            root->left = new BinaryTreeNode<T>(el);
        }
        cout << root->data <<" has right? (y/n)";
        cin >> ch;
        if (ch == 'Y' || ch == 'y') {
            cout << "Enter data for right  ";
            cin >> el;
            root->right = new BinaryTreeNode<T>(el);
        }
        createRecurisveHelper(root->left);
        createRecurisveHelper(root->right);
    }
};
#endif
