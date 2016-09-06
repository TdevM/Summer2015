#include<iostream>
using namespace std;
class Node {
    int data;
    Node * next;
    public:
    Node() : next(0) {}
    Node(int d) : data(d) , next(0) {}
    int getData() const { return data; }
    friend class LinkedList;
};
class LinkedList {
    Node * head;
    Node * tail;
    public:
    LinkedList(): head(0), tail(0) {}
    void clear() {
        while(head) {
            Node * temp = head;
            head = head->next;
            delete temp;
        }
        tail = 0;
    }
    ~LinkedList() {
        clear();
    }
    void insertAtTheEnd(int d) {
        Node * temp = new Node(d);
        insertAtTheEnd(temp);
    }
    void insertAtTheEnd(Node * n) {
        n->next = 0;
        if (!head) {
            head = tail = n;
            return;
        }
        tail->next = n;
        tail = n;
    }
    Node * softDeleteFromHead() {
        if (!head) return NULL;
        Node * temp = head;
        head = head->next;
        if (!head) tail = NULL;
        return temp;
    }
    bool isEmpty() {
        return head == NULL;
    }
    void radixSort() {
        if (!head || !head->next) return;
        int min = head->data;
        int max = head->data;
        Node * it = head->next;
        while (it) {
            if (it->data < min) {
                min = it->data;
            }
            if (it->data > max) {
                max = it->data;
            }
            it = it->next;
        }
        if (min < 0) {
            it = head;
            while (it) {
                it->data = it->data - min;
                it = it->next;
            }
            max-=min;
        }
        int totalrounds = 0;
        while (max > 0 ) {
            totalrounds++;
            max = max/10;
        }
        LinkedList buckets[10];
        int k = 1;
        for (int i = 0 ; i < totalrounds; i++) {
            while (!isEmpty()) {
                Node * temp = softDeleteFromHead();
                buckets[((temp->data)/k)%10].insertAtTheEnd(temp);
            }
            for (int j = 0; j < 10; j++) {
                while (!buckets[j].isEmpty()) {
                    Node * temp = buckets[j].softDeleteFromHead();
                    insertAtTheEnd(temp);
                }
            }
            k*=10;
        }
        if (min < 0) {
            Node * it = head;
            while (it) {
                it->data = it->data + min;
                it = it->next;
            }
        }
    }
    void printList() {
        Node * it = head;
        while (it) {
            cout << it->data << "-->";
            it = it->next;
        }
        cout << "NULL" << endl;
        return;
    }
};
int main() {
    LinkedList L;
    int N, val;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> val;
        L.insertAtTheEnd(val);
    }
    L.printList();
    L.radixSort();
    L.printList();
    return 0;
}
