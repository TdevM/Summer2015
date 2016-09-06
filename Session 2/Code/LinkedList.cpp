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
        return *this;
    }
    SingleLinkedList operator++(int temp) {
     //   SingleLinkedList temp = *this;
        // Modify current;
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
    void insertAtTheEnd(int);
    friend void friendFunction();
    friend ostream & operator<<(ostream &, const SingleLinkedList &);
};
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
int main() {
    friendFunction();
    SingleLinkedList L1;
    for (int i = 0; i < 10 ;i++) {
        L1.insertAtHead(i);
    }
    L1+=10;
    cout << L1 << endl;
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










