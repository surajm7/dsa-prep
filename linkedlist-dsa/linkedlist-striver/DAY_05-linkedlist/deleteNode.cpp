#include <bits/stdc++.h> 
using namespace std;

void deleteNode(ListNode *node) {
    // copy the value of next node
    node->val = node->next->val;
    // delete the next node
    node->next = node->next->next;
}