#include <bits/stdc++.h> 
using namespace std;


// class Node{
    
//     public:
//         int data;
//         Node* left;
//         Node* right;

//         Node(int d){
//             this->data =d;
//             this->left =NULL;
//             this->right=NULL;
//         }
// };

bool inorder(TreeNode<int>* root,vector<int>&in){
    if(root==NULL){
        return;
    }

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);


}

TreeNode<int>*inorderToBst(int s, int e,vector<int>&in){
    //base case
    if(s>e){
        retrun NULL;
    }

    int mid=(s+e)/2;
    TreeNode<int>*root=new TreeNode<int>(in[mid]);
    root->left=inorderToBst(s,mid-1,in);
    root->right=inorderToBst(mid+1,e,in);
    return root;
    
}

TreeNode<int>*balancedBst(TreeNode<int>*root){
    vector<int>inorderVal;
    //store inorder -> sorted values
    inorder(root,inorderVal);

    return inorderToBst(0,inorderVal.size()-1,inorderVal);

}