#include<iostream>
using namespace std;
class SingleLinkedList;
class Node {
    int data;
    Node * next;
    public:
    Node() : next(0), data(0) {}
    Node(int d) : next(0), data(d) {}
    Node(const Node & n) : next(0), data(n.data) {};
    friend class SingleLinkedList;
    friend ostream & operator<<(ostream &, const SingleLinkedList &);
};
class SingleLinkedList {
    Node * head;
    static int sharedmemory;
    void copyas(const SingleLinkedList & L) {
        const Node * it = L.head;
        Node * tail = 0;
        while (it) {
            Node *temp = new Node(*it);
            if (!head) {
                head = tail = temp;
            } else {
                tail->next = temp;
                tail = temp;
            }
            it = it->next;
        }
        return;
    }

    public:
    SingleLinkedList(): head(0) {}
    SingleLinkedList(const SingleLinkedList &L) : head(0) {
        copyas(L);
    }
    void clear() {
        while(head) {
            Node * temp = head;
            head = head->next;
            delete temp;
        }
    }
    ~SingleLinkedList() {
        clear();
        // (*this).clear();
        // this->clear();

    }
    SingleLinkedList & operator++() {
        Node * it = head;
        while (it) {
            it->data = it->data + 1;
            it = it->next;
        }
        return *this;
    }
    SingleLinkedList operator++(int dummy) {
        SingleLinkedList temp = *this;
        ++(*this);
        return temp;
    }
    SingleLinkedList & operator=(const SingleLinkedList & L) {
        clear();
        copyas(L);
        return *this;
    }
    SingleLinkedList operator+(int el) {
        SingleLinkedList temp = *this;
        temp.insertAtTheEnd(el);
        return temp;
    }
    SingleLinkedList & operator+=(int el) {
        insertAtTheEnd(el);
        return *this;
    }
    SingleLinkedList & operator+=(const SingleLinkedList & L) {
        // *this = *this + L;
        // return *this;
        SingleLinkedList temp (L);
        if (!head) {
            head = temp.head;
        } else {
            Node * it = head;
            while (it->next) {
                it = it->next;
            }
            it->next = temp.head;
        }
        temp.head = 0;
        return *this;
    }
    SingleLinkedList operator+(const SingleLinkedList & L) {
        SingleLinkedList ans = *this;
        SingleLinkedList ansright = L;
        if (!ans.head) {
            return ansright;
        }
        Node * temp = ans.head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next=ansright.head;
        ansright.head = 0;
        return ans;
    }
    void insertAtHead(int d) {
        Node * temp = new Node(d);
        temp->next = head;
        head = temp;
        return;
    }
    void printReverse() const {
        printReverseHelper(head);
    }
    private:
    static void printReverseHelper(const Node * head) {
        if (!head) return;
        printReverseHelper(head->next);
        cout << head->data << " ";
        return;
    }
    public:
    void printList() const {
        Node * it = head;
        while (it) {
            cout << it->data << "-->";
            it = it->next;
        }
        cout << "NULL " << endl;
        return;
    }
    void deleteFromHead() {
        if (head == NULL) return;
        Node * temp = head;
        head = head->next;
        delete temp;
        return;
    }
    int getDataForSharedMemory() {
        return sharedmemory;
    }
    void incrementSharedMemory() {
        sharedmemory++;
    }
    void insertAtTheEnd(int);
    friend void friendFunction();
    friend ostream & operator<<(ostream &, const SingleLinkedList &);
};
int SingleLinkedList::sharedmemory = 10;
ostream & operator<<(ostream & out, const SingleLinkedList & L) {
    const Node * it = L.head;
    while (it) {
        out << it->data << "-->";
        it = it->next;
    }
    return out;
}
void friendFunction() {
    SingleLinkedList L;
    cout << L.head  << endl;
    return;
}
void SingleLinkedList::insertAtTheEnd(int d) {
    Node *temp = new Node(d);
    if (!head ) { 
        head = temp;
        return;
    }
    Node *it = head;
    while (it->next) {
        it = it->next;
    }
    it->next = temp;
    return;
}
int & getValue() {
    static int x = 10;
    x++;
    return x;
}
int main() {
    SingleLinkedList L1, L2;
    cout << L1.sharedmemory << endl;
    cout << SingleLinkedList::sharedmemory <<endl;
    cout << L1.getDataForSharedMemory() << endl;
    L1.incrementSharedMemory();
    cout << L2.getDataForSharedMemory() << endl;
   /* int a = 10;
    int  & b = getValue();

    cout << ++(getValue()) << endl;
//    cout << ++(++a) << endl;
//    cout << ++(a++) << endl;
    return 0;*/
  /* 
    friendFunction();
    SingleLinkedList L1;

    for (int i = 0; i < 10 ;i++) {
        L1.insertAtHead(i);
    }
    L1+=10;
    cout << L1 << endl;
    cout << ++(++L1) << endl;
    cout << ++(L1++) << endl;
    cout << L1 << endl;*/
/*    SingleLinkedList L2 = L1;
    L2.deleteFromHead();
    L2.deleteFromHead();
    L2.printList();
    L1 += L2;
    L1.printList();
    L2.deleteFromHead();
    L2.printList();
    L1.printList();*/
    /*
    L1.insertAtHead(10);
    L1.printList(); 
    L1.deleteFromHead();
    L1.deleteFromHead();
    L1.printList();
    SingleLinkedList L2 = L1;
    L2.insertAtTheEnd(-10);
    L1.deleteFromHead();
    L1.deleteFromHead();
    L1.deleteFromHead();
    cout << "L2:";
    L2.printList();
    cout << "L1:";
    L1.printList();
    L2 = L1;
    L2.insertAtTheEnd(10);
    cout << "L2:";
    L2.printList();
    cout << "L1:";
    L1.printList();*/
/*    L2.deleteFromHead();
    L2.printList();
    L1.deleteFromHead();*/






    return 0;
}










