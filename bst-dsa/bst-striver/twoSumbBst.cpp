
#include <bits/stdc++.h>
 using namespace std;

class Node{
    
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data =d;
        this->left =NULL;
        this->right=NULL;
    }
};

bool inorder(Node* root,vector<int>&in){
    if(root==NULL){
        return;
    }

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);


}

bool twoSumInBst(Node* root,int target){
   vector<int> inorderVal;
   //store inorder ->sorted order
   inorder(root,inorderVal);

   //use 2 pointer approach to check if pair exists
   int i=0,j=inorderVal.size()-1;
   
    while(i<j){
        int sum=inorderVal[i]+inorderVal[j];
        if(sum==target){
            return true;
        }else if(sum>target){
            j--;
        }else{
            i++;
        }
    }
    return false;
}

// #include <bits/stdc++.h>
//  using namespace std;

// class BSTiterator {
    
//   private:  stack<TreeNode*> myStack;

// public:
//     BSTIterator(TreeNode *root) {
//         pushAll (root);
//     }

// /** @return whether we have a next smallest number */
//     bool hasNext() {

//         return !myStack.enpty();
//     }

// // @return the next smallest nunber */
//     int next() {
//         TreeNode *tmpNode = nyStack.top();
//         myStock.pop();
//         pushAll(tmpNode->right);
//         return tmpNode->val;

//     }

// private:
//     void pushAll(TreeNode* node){
//         for(;node!=NULL;myStack.push(node),node=node->left);
//     }    
// };    
// class Solution{
//     public:
//         bool findTarget(TreeNode* root ,int k){
//             if(!root) return false;
//             BSTIterator l(root,false);
//             BSTIterator r(root,true);

//             int i=l.next;
//             int j=r.next;
//             while(i<j){
//                 if(i+j ==k) return true;
//                 else if(i+j<k) i=l.next();
//                 else j=r.next();
//             }
//             return false;
//         }
// };