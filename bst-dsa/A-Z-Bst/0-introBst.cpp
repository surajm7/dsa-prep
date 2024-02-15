#include<bits/stdc++.h>
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

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            // cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }
}


Node* insertIntoBst(Node* root,int d){
    // base case

    if(root==NULL){
        root=new Node(d);
        return root;
    }

    if(d>root->data)
    //right part mey insert karrnaa h
        root->right =  insertIntoBst(root->right,d);
    else
    //left part mey insert karrnaa h
        root->left = insertIntoBst(root->right,d);

    return root;    
}


void inorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);
}


void preorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";
}



void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data !=-1){
       root = insertIntoBst(root,data);
        cin>>data;
    }
}

int main(){
    Node* root =NULL;
    cout<< "Enter data to create BST" << endl;
    takeInput(root);
    cout<< "Printing the BST"<<endl;

    levelOrderTraversal(root);

    cout<<"Printing Inorder" <<endl;
    inorder(root);

    cout<<"Printing preorder" <<endl;
    preorder(root);

    cout<<"Printing postorder" <<endl;
    postorder(root);

    return 0;
}