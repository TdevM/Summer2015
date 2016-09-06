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
void printList(const Node * head) {
    while(head != NULL) {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "NULL" << endl;
    return;
}
/*void appendEndtoFront(Node *(& head), int n){
if(head == NULL )
    return;
    Node*temp=head;
    int i=0;

while(head != NULL && i<n){
        head=head->next;
i++;
}

Node* temp =
Node *ollast= NULL;

return;
}*/








int main() {
    Node * head = NULL;
    insertAtTheBeginning(head, 5);
    insertAtTheBeginning(head, 6);
    insertAtTheBeginning(head, 7);
    insertAtTheBeginning(head, 8);
    insertAtTheBeginning(head, 9);
    insertAtTheBeginning(head, 10);
    insertAtTheBeginning(head, 1);
   // printList(head);
   // reversePrint(head);
    cout << endl;
   // while (head) {
   //     deleteFromTheEnd(head);
        printList(head);
   // }
//    appendEndtoFront(head,3);
}
