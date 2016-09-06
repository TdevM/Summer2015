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
struct myPair{
    Node<T> * add1;
    Node<T> * add2;
};


// This is a linked list class which has head and tail pointers. Implement all the below functions.
// Make sure that head and tail are always pointing to correct node after each operation.
// This is not double linked list. You only have one pointer in each node to store address of next element.
template <typename T>
class LinkedList {
    Node<T> * head;
    Node<T> * tail;
    // Prinvate function which empties the list.
    void clear() {
        while (head) {
            Node<T> * temp = head->next;
            delete head;
            head = temp;
        }
        tail = NULL;
    }
    // Private function which empties the list and then creates the copy of the LinkedList passed as argument
    void copyAs(const LinkedList & L) {
        clear();
       const Node<T> *it = L.head;
       while (it) {
           Node<T> * temp = new Node<T>(*it);
           temp->next = 0;
           if (head == NULL) {
               head = tail = temp;
           } else {
               tail->next = temp;
               tail = temp;
           }
           it = it->next;
       }
    }
    static Node<T>* selectionSortHelper(Node<T> * head) {
        if (head->next == NULL) {
            return head;
        }
        Node<T> * it = head->next;
        Node<T> * prevOfit = head;;
        Node<T> * smallest = head;
        Node<T> * prevOfSmallest = NULL;
        while (it) {
            if (it->data < smallest->data) {
                smallest = it;
                prevOfSmallest = prevOfit;
            }
            prevOfit = it;
            it = it->next;
        }
        if (prevOfSmallest == NULL) {
            head = head->next;
        } else {
            prevOfSmallest->next = smallest->next;
        }
        smallest->next = selectionSortHelper(head);
        return smallest;
    }
    static Node<T> * mergesortHelper(Node<T> * head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        Node <T> *prev = NULL;
        Node<T> * it1 = head;
        Node<T> * it2 = head;
        while (it2 && it2->next) {
            prev = it1;
            it1= it1->next;
            it2 = it2->next->next;
        }
        Node *head1 = head;
        prev->next = NULL;
        Node *head2 = it1;
        head1 = mergesortHelper(head1);
        head2 = mergesortHelper(head2);
        Node <T> * newhead = mergeHelper(head1, head2);
        return newhead;
    }
    static myPair<T>  reverseRecursiveHelper(Node<T> *tmpHead) {
        myPair<T> P;
        if (tmpHead->next == NULL) {
            P.add1 = P.add2 = tmpHead;
            return P;
        }
        Node<T> * curNode = tmpHead;
        tmpHead = tmpHead->next;
        curNode->next = 0;
        P = reverseRecursiveHelper(tmpHead);
        P.add2->next = curNode;
        P.add2 = curNode;
        return P;
    }

    static Node<T> * insertionSortHelper(Node<T> * sortHead, Node<T> * unsortedHead) {
        if (unsortedHead == NULL) {
            return sortHead;
        }
        Node<T> * temp = unsortedHead;
        unsortedHead = unsortedHead->next;
        temp->next = 0;
        // insert temp into sortedHead List;
        return  insertionSortHelper(sortHead, unsortedHead);
//        return newhead;
    }
   

    public:
    LinkedList() : head(0), tail(0) {}
    ~LinkedList() {
        clear();
    }
    LinkedList(const LinkedList & L) : head(0), tail(0) {
        copyAs(L);
    }
    LinkedList & operator=(const LinkedList & L) {
        copyAs(L);
        return *this;
    }
    // Inserts element at the end.
    void append(const T & el) {
        Node<T> * temp = new Node<T>(el);
        if (head == NULL) {
            tail = head = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    void selectionSort() {
        if (head == NULL || head->next == NULL) {
            return;
        }
        head = selectionSortHelper(head);
        tail = head;
        while(tail->next != NULL) {
            tail = tail->next;
        }
    }
    void mergeSort() {
        if (head == NULL || head->next == NULL) {
            return;
        }
        head = mergesortHelper(head);
        tail = head;
        while(tail->next != NULL) {
            tail = tail->next;
        }
    }
    // Inserts element at the beginning
    void prepend(const T & el) {
        Node<T> * temp = new Node<T>(el);
        if (head == NULL) {
            head = tail = temp;
        } else{
            temp->next = head;
            head = temp;
        }
    }

    // Delete one element from the beginning
    void deleteFromHead() {
    }

    // Delete one element from the end
    void deleteFromTail() {
    }

    // Insert at Kth Position
    void insertATKthPosition(int K, const T & el) {
    }

    // Delete from Kth Position
    void deleteAtKthPosition(int K, const T & el) {
    }

    // Return address of el in the list. If not present return NULL
    Node<T> * findElement(const T & el) const {

    }
    // Function which returns length of the linked list
    int length() const {
    }
    // function which returns address of Kth Node - returns NULL if K is out of Bound
    Node<T> * findKthElement() const {
    }
    // Swap ith and Jth Node of the linked list - Swap Nodes not the data. Do nothing if I or J are out of bounds
    void swap(int i, int j) {
    }
    // Reverses the linked list. You need to actually reverse the list not print in reverse order.
    void reverse() {
        if (head == NULL || head->next == NULL) {
            return;
        }
        myPair<T> P;
        P = reverseRecursiveHelper(head);
        head = P.add1;
        tail = P.add2;
    }
    // Sort the linked list using selection sort. You need to change next pointers in the data without using any array.
    void selectionsort() {
    }

    // Returns address of the mid node of the linked list
    Node<T> * findMidPoint() const {
       Node<T> * it1 = head;
       Node<T> * it2 = head;
       while (it2 && it2->next) {
           it1 = it1->next;
           it2 = it2->next->next;
       }
       return it1;
    }

    // Returns true if elements in the linked list make it palindrome for e.g: 1->13->4->5->4->13->1
    bool checkIfPalindrome() const {
    }

    // Rearrange the nodes such that all even elements are after odd elements. Again you need change next pointers not the data
    void arrangeEvenElementsAfterOddElements() {
    }

    // Rotate Linked List By K. You need to clockwise rotate the linked list by K. E.g. 1->2->3->4->5->6null and if K was 2 linked list should become 5->6->1->2->3->4->null
    void rotateClockWise(int K) {
    }

    // K reverse the linked list i.e. you reverse first K elements then reverse next K elements and join the linked list and so on.
    // For e.g. 3->4->5->2->6->1->9->10->NULL, and For K = 3 should become 5->4->3->1->6->2->10->9->NULL
    void kReverse(int K) {
    }

    // Remove Duplicates From the sortedList.
    // This function assumes the linked list is sorted and deletes duplicated nodes from the linked list.
    void removeDuplicatesFromSorted() {
    }
    

    void convertAnBn() {
        Node<T> * it = head;
        Node<T> * mid = findMidPoint();
        while(mid != NULL) {
            Node<T> * temp = mid->next;
            if (temp != NULL) {
                mid->next = it->next;
            }
            it->next = mid;
            mid = temp;
            it = it->next->next;
        }
    }


    // Return new linked list which is sorted of this and L.
    // You don't need to create new nodes. Just use nodes of this and L.
    // Your this and L should be empty after the operation.
    LinkedList merge(LinkedList & L) {
        LinkedList newlist;
        while (head != NULL && L.head != NULL) {
            Node<T> * temp;
            if (head->data < L.head->data) {
                temp = head;
                head = head->next;
            } else {
                temp = L.head;
                L.head = L.head->next;
            }
            temp->next = 0;
            if (newlist.head == NULL) {
                newlist.tail = newlist.head = temp;
            } else {
                newlist.tail->next = temp;
                newlist.tail = temp;
            }
        }
        if (head == NULL) {
            newlist.tail->next = L.head;
            newlist.tail = L.tail;
        } else {
            newlist.tail->next = head;
            newlist.tail = tail;
        }
        L.head = L.tail = head = tail = NULL;
        return newlist;
    }
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
