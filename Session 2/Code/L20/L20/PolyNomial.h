#ifndef POLY_H
#define POLY_H
class Node {
    float coef;
    int power;
    Node * next;
    Node * prev;
    public:
        Node() : coef(0), power(0), next(0), prev(0) {}
        Node(int c, int p) : coef(c), power(p), next(0), prev(0) {}
        Node(const Node & n): coef(c.coef), power(c.power), next(0), prev(0) {}
    friend class Polynomial;
};
class Polynomial {
    Node * head;
    Node * tail;
    int degree;
    int numberofterms;
    public:
    Polynomial() : head(0), tail(0), degree(0), numberofterms(0) {}
    const Polynomial operator+(const Polynomial & b) const {
        Polynomial temp = *this;
        temp+=b;
        return temp;
    }
    Polynomial & operator+=(const Polynomial & b) {
        Node * it1 = head;
        const Node * it2 = b.head;
        if (!it1 && !it2) return;
        if (!it1 && it2) {
            *this = b;
            return *this;
        }
        if (it2->power > it1->power) {
            Node * temp = new Node(*it2);
            head = temp;
            head->next = it1;
            it1->prev = head;
            it2 = it2->next;
        }
        while(it1 && it2) {
            if (it1->power == it2->power) {
                it1->coef+=it2->coef;
                it1 = it1->next;
                it2 = it2->next;
            } else if (it1->power > it2->power) {
                it1 = it1->next;
            } else {
                Node * temp = new Node(*it2);
                temp->next = it1;
                it1->prev->next = temp;
                temp->prev = it1->prev;
                it1->prev = temp;
                it2 = it2->next;
            }
        }
        while(it2) {
            Node * temp = new Node(*it2);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
            it2 = it2->next;
        }
        return *this;
    }

};
#endif
