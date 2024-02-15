#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *dummy = new ListNode(); 
        ListNode *temp = dummy; 
        int carry = 0;
        while( (l1 != NULL || l2 != NULL) || carry) {
            int sum = 0; 
            if(l1 != NULL) {
                sum += l1->val; 
                l1 = l1 -> next; 
            }
            
            if(l2 != NULL) {
                sum += l2 -> val; 
                l2 = l2 -> next; 
            }
            
            sum += carry; 
            carry = sum / 10; 
            ListNode *node = new ListNode(sum % 10); 
            temp -> next = node; 
            temp = temp -> next; 
        }
        return dummy -> next; 

        // 2ND APPROACH
        ListNode head;
        ListNode *curr = &head;
        int carry = 0;

        while(l1 || l2 || carry) {
            if(l1) {
                carry += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                carry += l2->val;
                l2 = l2->next;
            }
            // create new node
            curr->next = new ListNode(carry % 10);
            carry /= 10;
            // move curr to the last node (new node added)
            curr = curr->next;
        }
        return head.next;
    }
};