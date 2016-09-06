#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include<iostream>
using namespace std;
template <typename T> class LinkedList;
template <typename T>
class Node {
    T data;
    Node * next;
    public:
    Node() : next(0) {}
    Node(const T & el) : data(el), next(0) {}
    Node(const T & el, Node * ad): data(el), next(ad) {}
    T getData() const {
        return data;
    }
    template <typename V>
        friend class LinkedList;
    template<typename V>
       friend ostream & operator<<(ostream &, const LinkedList<V> &);
};

template <typename T>
class LinkedList {
    Node<T> * head;
    void clear() {
        while (head != NULL) {
            Node<T> * temp = head->next;
            delete head;
            head = temp;
        }
    }
    void copyAs(const LinkedList & L) {
        clear();
        const Node<T> * it = L.head;
        Node<T> * prev = 0;
        while (it != 0) {
            Node<T> * temp = new Node<T>(*it);
            temp->next = 0;
            if (head == NULL) {
                head = temp;
            } else {
                prev->next = temp;
            }
            it = it->next;
            prev = temp;
        }
    }
    public:
    LinkedList() : head(0) {}
    ~LinkedList() {
        clear();
    }
    LinkedList(const LinkedList & L) : head(0) {
        copyAs(L);
    }
    LinkedList & operator=(const LinkedList & L) {
        copyAs(L);
        return *this;
    }
    void append(const T & el) {
        Node<T> * temp = new Node<T>(el);
        if (head == 0) {
            head = temp;
            return;
        }
        Node<T> * it = head;
        while(it->next !=0) {    //while ((*it).next != 0)
            it = it->next;
        }
        it->next = temp;
    }
    // Insert at the head
    void prepend(const T & el) {
        Node<T> * temp = new Node<T>(el);
        temp->next = head;
        head = temp;
    }
 //   const Node * findElement(const T & el) const {

   // }
    template<typename V>
       friend ostream & operator<<(ostream &, const LinkedList<V> &);
};

template <typename T>
ostream & operator<<(ostream & obj, const LinkedList<T> & L) {
    const Node<T> * it = L.head;
    while (it != NULL) {
        obj << it->data << "-->";
        it = it->next;
    }
    obj << "NULL";
    return obj;
}
#endif
