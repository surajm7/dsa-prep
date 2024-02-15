#include <bits/stdc++.h> 
using namespace std;


ListNode* reverseKGroup(ListNode* head, int k) {
    if(head==NULL || k==1) return head;

    ListNode *dummy=new ListNode(0);
    dummy->next=head;

    ListNode *cur=dummy ,*nex=dummy ,*pre=dummy;
    
    int cnt=0;
    while(cur->next!=NULL){
        cur=cur->next;
        cnt++;
    }

    while(cnt>=k){
        cur=cur->next;
        cnt++;
    }

    while(cnt>=k){
        cur=pre->next;
        nex=cur->next;
        for(int i=1;i<k;i++){
            cur->next=nex->next;
            nex->next=pre->next;
            pre->next=nex;
            nex=cur->next;
        }
        pre=cur;
        cnt-=k;
    }
    return dummy->next;
}

 // helper function to calculate the size of the linked list
    int length(ListNode *head) {
        int size = 0;
        while(head) {
            size++;
            head = head->next;
        }
        return size;
    }
    
    // helper function to add node at the starting of the list
    void addFirst(ListNode *node) {
        if(th == NULL)
            th = tt = node;
        else {
            node->next = th;
            th = node;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k){
        // edge cases
        if(!head || !head->next || k == 1)
            return head;
        // find the length of the list
        int size = length(head);
        ListNode *curr = head;
        
        // original head and tails for the final merged linked list
        ListNode *oh = NULL, *ot = NULL;
          
        while(size >= k) {
            int temp = k;
            // reverse the links of K nodes
            while(temp--) {
                // take the left most node
                ListNode *N = curr->next;
                // break the link
                curr->next = NULL;
                addFirst(curr);
                // update values for next iteration
                curr = N;
            }
            // first set of k reversed nodes
            if(!oh) {
                oh = th;
                ot = tt;
            }
            else {
                ot->next = th;
                ot = tt;
            }
            
            // reset th and tt
            th = tt = NULL;
            // decrease size
            size -= k;
        }
        // attach the remaining part: residual group of size < k 
        if(size)
            ot->next = curr;
        return oh;


    }

    //recursive solution
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cursor = head;
        for(int i = 0; i < k; i++){
            if(cursor == nullptr) return head;
            cursor = cursor->next;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;
        for(int i = 0; i < k; i++){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }


Node* kReverse(Node* head, int k) {
    //base call
    if(head == NULL) {
        return NULL;
    }

    //step1: reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count= 0;
    
    while( curr != NULL && count < k ) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    //step2: Recursion dekhlega aage ka 
    if(next != NULL) {
        head -> next = kReverse(next,k);
    }
    
    //step3: return head of reversed list
    return prev;
}