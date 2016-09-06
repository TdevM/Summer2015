#include<iostream>
using namespace std;

class Node{
    int data;
    Node *next=NULL;
    int capacity;
    int top;
    public:
    Node():top(0),int capacity(10){}
};


class StackAsLL{
public:

    void push(Node *head,int el){
        Node *top=head;
        if(top>=capacity){
            cout<<"STACK FULL"<<endl;
        }
        else
             Node *newnode = new Node;
             newnode->data=el;
             newnode->next=head;
             newnode=head;
             return;
}

   // void printStack(top){



    //}
    void pop(){
    }
    int getTOP(){
    }
    int size(){
    }


};


int main(){
    Node *head=NULL;
push(5);
return 0;
}
