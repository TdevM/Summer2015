#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include<vector>
#include<queue>
using namespace std;
template <typename T>
class BSTNode {
    T data;
    BSTNode *left;
    BSTNode *right;
    public:
    BSTNode(): left(NULL), right(NULL){}
    BSTNode(const T & d) : data(d) , left(NULL), right(NULL){}
    const T & getData() const {
        return data;
    }

    template<typename V>
        friend class BST;
};
template<typename T>
class BST {
    BSTNode<T> * root;
    public:
    BST() : root(NULL) {}
    BST(const vector<T> &pre, const vector<T> & in) : root(0){
        if (pre.size() != in.size()) {
            throw "Improper data";
        }
        if (pre.size() == 0) {
            return;
        }
        root = createFromPreAndIn(pre, in, 0, pre.size() - 1, 0, in.size() - 1);
    }
    ~BST() { clear(); }
    BST(const BST & T1) : root(NULL) {
        if(T1.root == NULL) { return;}
        root = copyas(T1.root);
    }
    BST & operator=(const BST & T1) {
        clear();
        root = copyas(T1.root);
        return *this;
    }
    bool isEmpty() { return root == NULL; }
    void clear() {
        clearHelper(root);
        root = NULL;
    }
    int height() {
        return heightHelper(root);
    }
    void insert(const T & el) {
        root = insertHelper(root, el);
    }
    void remove(const T & el) {
        root = removeHelper(root, el);
    }
    void insertIterative(const T & el) {
        BSTNode<T> * temp = new BSTNode<T>(el);
        if (!root) {
            root = temp;
            return;
        }
        BSTNode<T> * it = root, *prev = 0;
        while (it) {
            prev = it;
            if (it->data < el) {
                it = it->right;
            } else {
                it = it->left;
            }
        }
        if (prev->data < el) {
            prev->right = temp;
        } else {
            prev->left = temp;
        }
    }
    private:
    static BSTNode<T> * removeHelper(BSTNode<T> * root, const T & el) {
        if (root->data == el) {
            if (!root->left && !root->right) {
                delete root;
                return NULL;
            } else if (!root->left && root->right) {
               BSTNode<T> * temp = root->right;
              delete root;
              return temp;
            } else if (root->left && !root->right) {
               BSTNode<T> * temp = root->left;
              delete root;
              return temp;
            } else {
                BSTNode<T> * rightmin = findMinHelper(root->right);
                root->data = rightmin->data;
                root->right = removeHelper(root->right, rightmin->data);
                return root;
            }
        } else if (root->data < el) {
            root->right = removeHelper(root->right, el);
            return root;
        } else {
            root->left = removeHelper(root->left, el);
            return root;
        }
    }
    static BSTNode<T> * findMinHelper(BSTNode<T> * root) {
        if (!root) return NULL;
        if (!root->left) return root;
        return findMinHelper(root->left);
    }
    static BSTNode<T>* insertHelper(BSTNode<T> * root, const T & el) {
        if (root == NULL) {
            root = new BSTNode<T>(el);
            return root;
        }
        if (root->data < el) {
            root->right = insertHelper(root->right, el);
        } else {
            root->left = insertHelper(root->left, el);
        }
        return root;
    }
    static int heightHelper(BSTNode<T> * root) {
        if (root == NULL) {
            return 0;
        }
        return max(heightHelper(root->left), heightHelper(root->right)) + 1;
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

    static BSTNode<T>* createFromPreAndIn(const vector<T> &pre, const vector<T> &in,
            int prestart, int preend, int instart, int inend) {
        if (prestart > preend) {
            return NULL;
        }
        BSTNode<T> *root = new BSTNode<T>(pre[prestart]);
        int pos = findInInorder(in, instart, inend, pre[prestart]);
        int leftpreend = prestart+pos-instart;
        root->left = createFromPreAndIn(pre, in, prestart+1 , leftpreend , instart, pos-1);
        root->right = createFromPreAndIn(pre, in, leftpreend+1, preend, pos+1, inend);
        return root;
    }
    static BSTNode<T>* copyas( BSTNode<T> * fromroot) {
        if (fromroot == NULL) {
            return NULL;
        }
        BSTNode<T> * root = new BSTNode<T>(fromroot->data);
        root->left = copyas(fromroot->left);
        root->right = copyas(fromroot->right);
        return root;
    }
    static void clearHelper(BSTNode<T> * root) {
        if (root == NULL) return;
        clearHelper(root->left);
        clearHelper(root->right);
        delete root;
        return;
    }
};
#endif
