#include <bits/stdc++.h>
 using namespace std;


ListNode* removeNthFromEnd(ListNode *head, int n) {
    ListNode * start =new ListNode();
    start->next=head;
    ListNode *slow = head;
    ListNode *fast = head;
    // move fast pointer by n steps
    for(int i = 0; i < n; i++)
        fast = fast->next;
    // edge cases: head node is to be deleted
    if(!fast)
        return head->next;
    
    // while fast reaches the last node
    while(fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    // delete slow->next node
    slow->next = slow->next->next;
    return start->next;
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