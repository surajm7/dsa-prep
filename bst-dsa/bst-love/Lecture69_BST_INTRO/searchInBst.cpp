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

Node* insertIntoBst(Node* &root,int d){
    // base case

    if(root==NULL){
        root=new Node(d);
        return root;
    }

    if(d>root->data)
        root->right =  insertIntoBst(root->right,d);
    else
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

bool searchInBst(BinaryTreeNode<int>*root,int x){
    recursion ways
    if(root==NULL){
        return false;
    }

    if(root->data==x)  return true;

    if(root->data >x){
        return searchInBst(root->left,x);
    }else{
        return searchInBst(root->right,x);
    }

//iterative ways
    BinaryTreeNode<int>*temp = root;

        while(temp!=NULL){
            if(temp->data==x){
                return true;
            }
            if(temp->data>x){
                temp=temp->left;
            }else{
                temp=temp->right;
            }
        }
        return false;
}

//finding the min value
Node* minVal(Node* root){
    Node* temp =root;
    while(temp->left !=NULL){
        temp=temp->left;
    }
    return temp;
}


//finding the max value
Node* maxVal(Node* root){
    Node* temp =root;
    while(temp->right !=NULL){
        temp=temp->right;
    }
    return temp;
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
// O(h) worst case:O(N)
Node deleteFromBST(Node* root ,int val){
    //base case
    if(root==NULL)  return root;

    if(root->data==val){
        //0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        //1 CHILD
        //left child
        if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }

        //right child
        if(root->left==NULL && root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }

         //2 child
        if(root->left!=NULL && root->right!=NULL){
            int mini=minVal(root->right)->data;
            root->data=mini;
            root->right=deleteFromBST(root->right,mini);
           
            return root;
        }
    }else if(root->data>val){
        //left part me jao
        root->left=deleteFromBST(root->left,val);
        return root;
    }else{
        //right part mey jao
        root->right=deleteFromBST(root->right,val);
        return root;
    }
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

    cout<<"min value is"<< minVal(root)->data<<endl;

    cout<<"Max value is"<< maxVal(root)->data<<endl;

    //deletion
    root=deleteFromBST(root,50);
    cout<< "Printing the BST"<<endl;

    levelOrderTraversal(root);
    cout<<"Printing Inorder" <<endl;
    inorder(root);

    return 0;

}