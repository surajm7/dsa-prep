/*
    Problem Link: https://leetcode.com/problems/merge-two-sorted-lists/
*/

struct ListNode {
    int val;
    ListNode *next;

    ListNode(): val(0), next(NULL) {}
    ListNode(int x): val(x), next(NULL) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
    // base cases
    if(!l1)
        return l2;
    else if(!l2)
        return l1;
    
    if(l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        // when list1 is empty then 
        // our output will be same as list2
        if(l1 == NULL) return l2; 

        if(l2 == NULL) return l1;

        // pointing l1 and l2 to smallest and greatest one
        if(l1->val > l2->val){
            //  std::swap(l1,l2);
            ListNode temp =l1;
            l1=l2;
            l2=temp;
        }

        // act as head of resultant merged list
        ListNode* res = l1;

        while(l1 != NULL && l2 != NULL) {
 
            ListNode* temp = NULL;
            while(l1 != NULL && l1->val <= l2->val) {
                temp = l1;//storing last sorted node  
                l1 = l1->next;
            }
            // link previous sorted node with 
            // next larger node in list2
            temp->next = l2;
            std::swap(l1,l2);
        }
        return res;
    }
