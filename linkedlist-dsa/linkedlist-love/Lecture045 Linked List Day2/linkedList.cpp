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

// Reverse a linked list

Node* reverseLinkedl(Node* head){
    Node* prev =NULL;
    Node*curr =head;
     
    reverseLinlLRecursive(head,curr,prev);
    return head;
    if(head==NULL || head->next==NULL){
        return head;
    }

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

void insertAtTail(Node* &tail, int d) {
     // new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail  = temp;
}

void print(Node* &head) {
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertAtPosition(Node* &tail, Node* & head, int position, int d) {


    //insert at Start
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
}

void deleteNode(int position, Node* & head) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        //memory free start ndoe
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;
    }
}

int main() {
    
    
    return 0;
}