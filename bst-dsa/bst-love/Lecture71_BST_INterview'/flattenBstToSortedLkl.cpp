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


Node<int* flatten(Node<int>*root){
    vector<int> inorderVal;
    //store inorder ->sorted values
    inorder(root,inorderVal);
    int n =inorderVal.size();

    Node<int>* newRoot =new Node<int>(inorderVal[0]);

    Node<int>* curr=newRoot;

    //2nd step
    for(int i=1;i<n;i++){
        Node<int>*temp=new Node<>(inorderVal[i]);
        curr->left=NULL;
        curr->right=temp;
        curr=temp;
    }

    //3rd step
    curr->left =NULL;
    curr->right =NULL;

    return newRoot;

}