#include <bits/stdc++.h>
 using namespace std;


class Solution{
    void changeTree(BinaryTree<int>*root){
        if(root==NULL) return;
        int child =0;
        if(root->left)
            child+=root->left->data;

        if(root->right)
            child+=root->right->data;

        if(child>=root->data){
            root->data=child;
        }else{
            if(root->left){
                root->left->data=root->data;
            }else if(root->right){
                root->right->data=root->data;
            }
        }
        changeTree(root->left);
        changeTree(root->right);

        int tot=0;
        if(root->left) tot+=root->left->data;
        if(root->right) tot+=root->right->data;

        if(root->left or root->right){
            root->data=tot;
        }
    }

}