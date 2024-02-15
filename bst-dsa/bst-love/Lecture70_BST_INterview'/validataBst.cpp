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
//validate Binary search tree
bool isBST(BinaryTreeNode<int> *root ,int min ,int max){ 
    
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

//Kth-smallest element
int solve(BinaryTreeNode<int> *root , int &i , int k){
    if(root==NULL)  return -1;

    int left =solve(root->left,i,k);

    if(left !=-1)  return left;

    i++;
    if(i==k)
        return root->data;
    // from right part

    return solve(root->right,i,k);
}

int kthSmallest(BinaryTreeNode<int> *root,int k){
    int ans =solve(root,i,k);
    rteurn ans;
}



// bool searchInBst(BinaryTreeNode<int>*root,int x){
//     // if(root==NULL){
//     //     return false;
//     // }

//     // if(root->data==x)  return true;

//     // if(root->data >x){
//     //     return searchInBst(root->left,x);
//     // }else{
//     //     return searchInBst(root->right,x);
//     // }

//     BinaryTreeNode<int>*temp = root;

//         while(temp!=NULL){
//             if(temp->data==x){
//                 return true;
//             }
//             if(temp->data>x){
//                 temp=temp->left;
//             }else{
//                 temp=temp->right;
//             }
//         }
// }

Node* minVal(Node* root){
    Node* temp =root;

    while(temp->left !=NULL){
        temp=temp->left;
    }

    return temp;
}

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

    return 0;

}