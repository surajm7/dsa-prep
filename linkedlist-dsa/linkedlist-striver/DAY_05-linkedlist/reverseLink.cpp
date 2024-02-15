#include<iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }

};

//Midle of Linked list
Node* getMiddle(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    //2 nodes -- needed or not??
    if(head->next->next ==NULL){
        return head->next;
    }

    Node* slow=head;
    Node* fast=head->next;

    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
    }
    return slow;
}


Node* reverseList(Node* head) {
        Node* newHead=NULL;
        while(head!=NULL){
          Node* next=head->next;
            head->next=newHead;
            newHead=head;
            head=next;
        }
        return newHead;
}


// Reverse a linked list
Node* reverseLinkedl(Node* head){
    // Node* prev =NULL;
    // Node*curr =head;
     
    // reverseLinlLRecursive(head,curr,prev);
    // return head;
    // if(head==NULL || head->next==NULL){
    //     return head;
    // }

    Node* prev =NULL;
    Node*curr =head;
    Node* forw =NULL;

    while(curr!=NULL){
        forw =curr->next;
        curr->next=prev;
        prev=curr;
    }
    return prev;
}


void reverseLinlLRecursive(Node* &head,Node* curr,Node* prev){
    //base case
    if(curr==NULL){
        head=prev;
        return;
    }

    Node* forw =curr->next;
    reverseLinlLRecursive(head,forw,curr);
    curr->next=prev;
}


void insertAtHead(Node* &head, int d) {

    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

int main() {
    
    
    return 0;
}