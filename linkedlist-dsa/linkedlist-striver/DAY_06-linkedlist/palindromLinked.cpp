#include <bits/stdc++.h>
 using namespace std;

class Solution{
  private:

    bool checkPalindrome(vector<int> arr){
        int n =arr.size();
        int s =0;
        int e=n-1;

        while(s<=e){
            if(arr[s]!=arr[e]){
                return 0;
            }
            s++;
            e--;
        }
        return 1;
    }


  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node* head){
        vector<int> arr;

        Node* temp =head;
        while(temp!=NULL){
            arr.push_back(temp->data);
            temp=temp->next;
        }
        return checkPalindrome(arr);
    }


    bool isPalindrome(Node *head)
    {
        if(head -> next == NULL) {
            return true;
        }
        
        //step 1 -> find Middle
        Node* middle = getMid(head);
        //cout << "Middle " << middle->data << endl;
        
        //step2 -> reverse List after Middle
        Node* temp = middle -> next;
        middle -> next = reverse(temp);
        
        //step3 - Compare both halves
        Node* head1 = head;
        Node* head2 = middle -> next;
        
        while(head2 != NULL) {
            if(head2->data != head1->data) {
                return false;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
    
        //step4 - repeat step 2
        temp = middle -> next;
        middle -> next = reverse(temp);
        
        return true;
     }
};

bool isPalindrome(ListNode *head) {
    if(head==NULL || head->next==NULL){
        return true;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    // find middle of the linked list
    while(fast->next!=NULL && fast->next->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // move fast to head
   slow->next=reverseList(slow->next);
   slow=slow->next;

    while(slow!=NULL){
        if(head>val != slow->val)
            return false;
        // move 1 step each
        head=head->next;
        slow = slow->next;
    }
    return true;
}
