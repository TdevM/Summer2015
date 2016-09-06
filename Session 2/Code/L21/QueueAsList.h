#ifndef QUEUE_AS_LIST_H
#define QUEUE_AS_LIST_H
template <typename T>
class Node {
    T data;
    Node * next;
    Node() : next(0), data(0) {}
    Node(const type &d) : next(0), data(d) {}
    Node(const Node & n) : next(0), data(n.data) {};
    template <typename U>
        friend class Queue;
};

template <typename T>
class Queue {
    Node<T> * head;
    Node<T> * tail;
    int count;
    public:
    Queue() : head(0), tail(0), count(0) {
    }
    ~Queue() {
        clear();
    }
    Queue(const Queue & Q): head(0) , tail(0), count(0) {

    }
    Queue & operator=(const Queue & Q) {

    }
    bool isEmpty() const {
        return head == NULL;
    }
    int size() const {
        return count;
    }
    void clear() {
        while(head) {
            Node<T> * temp = head;
            head = head->next;
            delete temp;
        }
        tail = 0;
        return;
    }
    void enqueue(const T & el) {
        Node<T> * temp = new Node<T>(el);
        count++;
        if (isEmpty()) {
            head = tail = temp;
            return;
        }
        tail->next = temp;
        tail = temp;
        return;
    }
    void dequeue() {
        if (isEmpty()) {
            return;
        }
        Node <T> * temp = head;
        head = head->next;
        delete temp;
        if (!head) tail = 0;
        count--;
        return;
    }
    const T & front() const {
        return head->data;
    }
    T & front() {
        return head->data;
    }

};
#endif
