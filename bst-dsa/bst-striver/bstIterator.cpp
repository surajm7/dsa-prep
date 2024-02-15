#include <bits/stdc++.h> 
using namespace std;

class BSTiterator {
private:  stack<TreeNode*> myStack;

public:
    BSTIterator(TreeNode *root) {
        pushAll (root);
    }

/** @return whether we have a next smallest number */
    bool hasNext() {

        return !myStack.empty();
    }

// @return the next smallest nunber */
    int next() {
        TreeNode *tmpNode = nyStack.top();
        myStock.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;

    }

private:
    void pushAll(TreeNode* node){
        for(;node!=NULL;myStack.push(node),node=node->left);
    }    
};    