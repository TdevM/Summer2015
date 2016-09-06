#include<iostream>
using namespace std;
struct Node {
    int data;
    Node * next;
};
void insertAtTheBeginning(Node *(&head), int data) {
    Node * curr = new Node;
    curr->data = data;
    (*curr).next = head; // curr->next = head;
    head = curr;
    return;
}
void deleteFromTheEnd(Node *(&head)) {
    if (head == NULL) {
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node * it = head;
    while ((*(*it).next).next != NULL) { // while (it->next->next != NULL) {
        it = it->next;
    }
    delete it->next;
    it->next = 0;
    return;
}
void reversePrint(const Node * head) {
    if (head == NULL) {
        cout << "NULL";
        return;
    }
    reversePrint(head->next);
    cout << "<--"<<head->data;
    return;
}
Node * removeLargestAndReturn(Node * & head) {
    if (!head) return NULL;
    Node *largest = head, *prevoflargest = NULL, *it = head->next, *prevofit = head;
    while(it) {
        if (it->data > largest->data) {
            largest = it;
            prevoflargest = prevofit;
        }
        prevofit = it;
        it = it->next;
    }
    if (prevoflargest == NULL) {
        head = head->next;
    } else {
        prevoflargest->next = largest->next;
    }
    largest->next = NULL;
    return largest;
}
void selectionsort(Node * &head) {
    Node * newhead = NULL;
    while (head) {
        Node * temp = removeLargestAndReturn(head);
        temp->next = NULL;
        if (!newhead) {
            newhead = temp;
        } else {
            temp->next = newhead;
            newhead= temp;
        }
    }
    head = newhead;
}
void printList(const Node * head) {
    while(head != NULL) {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "NULL" << endl;
    return;
}
void reverseApproach2(Node * it, Node *&head) {
    if (it->next == NULL) {
        head = it;
        return;
    }
    Node * nextnode = it->next;
    reverseApproach1Helper(it->next, head);
    nextnode->next = it;
    it->next = NULL;
    return;

}
void reverseApproach1Helper(Node * head) {
    if (head->next == NULL) {
        return;
    }
    Node * nextnode = head->next;
    reverseApproach1Helper(head->next);
    nextnode->next = head;
    head->next = NULL;
    return;
}
void reverseApproach1(Node * &head) {
    if (!head || !head->next) {
        return;
    }
    Node * tail = head;
    while (tail->next) {
        tail = tail->next;
    }
    reverseApproach1Helper(head);
    head = tail;
}
int main() {
    Node * head = NULL;
    insertAtTheBeginning(head, 5);
    insertAtTheBeginning(head, 6);
    insertAtTheBeginning(head, 7);
    insertAtTheBeginning(head, 8);
    insertAtTheBeginning(head, 9);
    insertAtTheBeginning(head, 10);
    insertAtTheBeginning(head, 1);
    printList(head);
    reverseApproach1(head);
    printList(head);
    selectionsort(head);
    printList(head);
/*    reversePrint(head);
    cout << endl;
    while (head) {
        deleteFromTheEnd(head);
        printList(head);
    }*/
}
