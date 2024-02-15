//validate Binary search tree
#include <bits/stdc++.h> 
using namespace std;

bool isValidBST(TreeNode *root ,int min ,int max){ 
    
    if(root==NULL){
        return true;
    }

    if(root->data>=min && root->data <=max){
        bool left = isBST(root->left,min,root->data);
        bool right = isBST(root->right,root->data,max);
        return left && right;
    }else{
        return false;
    }

}

bool isBST(TreeNode * root){
    retrun isValidBST(root,INT_MIN,INT_MAX);
}