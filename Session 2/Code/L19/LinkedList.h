#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include<iostream>
using namespace std;

template <typename V>
class SingleLinkedList;

template <typename type>
class Node {
    public:
    type data;
    Node * next;
    Node() : next(0), data(0) {}
    Node(const type &d) : next(0), data(d) {}
    Node(const Node & n) : next(0), data(n.data) {};
    template <typename U>
        friend class SingleLinkedList;
    template <typename U>
        friend ostream & operator<<(ostream &, const SingleLinkedList<U> &);
};

template <typename T>
class SingleLinkedList {
    Node<T> * head;
    void copyas(const SingleLinkedList & L) {
        const Node<T> * it = L.head;
        Node<T> * tail = 0;
        while (it) {
            Node<T> *temp = new Node<T>(*it);
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
            Node<T> * temp = head;
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
        Node<T> * it = head;
        while (it) {
            it->data++;
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
    SingleLinkedList operator+(const T & el) {
        SingleLinkedList temp = *this;
        temp.insertAtTheEnd(el);
        return temp;
    }
    SingleLinkedList & operator+=(const T & el) {
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
            Node<T> * it = head;
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
        Node<T> * temp = ans.head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next=ansright.head;
        ansright.head = 0;
        return ans;
    }
    void insertAtHead(const T & d) {
        Node<T> * temp = new Node<T>(d);
        temp->next = head;
        head = temp;
        return;
    }
    void printReverse() const {
        printReverseHelper(head);
    }
    private:
    static void printReverseHelper(const Node<T> * head) {
        if (!head) return;
        printReverseHelper(head->next);
        cout << head->data << " ";
        return;
    }
    public:
    void printList() const {
        Node<T> * it = head;
        while (it) {
            cout << it->data << "-->";
            it = it->next;
        }
        cout << "NULL " << endl;
        return;
    }
    void deleteFromHead() {
        if (head == NULL) return;
        Node<T> * temp = head;
        head = head->next;
        delete temp;
        return;
    }
    void insertAtTheEnd(const T &);
    template<typename U>
    friend ostream & operator<<(ostream &, const SingleLinkedList<U> &);
};
template<typename T>
ostream & operator<<(ostream & out, const SingleLinkedList<T> & L) {
    const Node<T> * it = L.head;
    while (it) {
        out << it->data << "-->";
        it = it->next;
    }
    return out;
}
template<typename T>
void SingleLinkedList<T>::insertAtTheEnd(const T & d) {
    Node<T> *temp = new Node<T>(d);
    if (!head ) { 
        head = temp;
        return;
    }
    Node<T> *it = head;
    while (it->next) {
        it = it->next;
    }
    it->next = temp;
    return;
}
#endif









