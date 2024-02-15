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