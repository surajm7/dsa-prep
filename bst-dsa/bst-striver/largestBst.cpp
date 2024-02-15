#include <bits/stdc++.h> 
using namespace std;

class NodeValue{
    int minNode ,minNode,maxSize;
    NodeValue(int minNode ,int maxNode ,int maxSize){
        this->maxNode =maxNode;
        this->minNode =minNode;
        this->maxSize =maxSize;
    }
};
class Solution{
    private:
        NodeValue helper(TreeNode* root){
            //An empty tree ia a BST of size 0
            if(!root){
                retrun NodeValue(INT_MAX,INT_MIN,0);
            }

            //GET VALUES FROM LEFT AND RIGHT SUBTREE OF CURRENT TREE
            auto left =helper(root->left);
            auto right =helper(root->right);

            //current Node is grater than max in left AND smaller than min in right
            if(left.maxNode<root->val&&root->val<right.minNode){
                //IT is a BST
                return NodeValue(min(root->val,left.minNode),max(root->val,right.maxNode),left.maxSize+right.maxSize+1);
            }
            //otherwise , return [-inf,inf] so that parent can't be valid bst
            return NodeValue(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));
        }
    public:
        NodeValue largestBSTSubtree(Treenode* root){
            retrun helper(root).maxSize;
        }
};