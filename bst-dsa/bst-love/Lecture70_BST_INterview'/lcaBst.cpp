#include <bits/stdc++.h>
 using namespace std;


TreeNode<int>* LCAinBST(TreeNode<int>*root ,TreeNode<int>*P,TreeNode<int>*Q){
    //base case

    // if(root==NULL){
    //     return NULL;
    // }

    while(root!=NULL){
        if(root->data <P->data && root->data<Q->data )
             root=root->right;

        else if(root->data>P->data && root->data>Q->data )
            root = root->left;
        else{
            return root;
        }    

    }

    // if(root->data <P->data && root->data<Q->data )
    //     return LCAinBST(root->right,P,Q);

    // if(root->data>P->data && root->data>Q->data )
    //     return LCAinBST(root->left,P,Q);

    // return root;    
}