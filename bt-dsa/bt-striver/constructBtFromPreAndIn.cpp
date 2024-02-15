
//   Definition for a binary tree node.
  struct TreeNode {
     int val;
      TreeNode *left;
     TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


#include <bits/stdc++.h> 
using namespace std;

class Solution {
private:
      TreeNode* buildTree_(vector<int>& preorder,int psi,int pei, vector<int>& inorder,int isi,int iei) {
        if(isi>iei)   return NULL;
         
       TreeNode* node = new TreeNode(preorder[psi]);
        int idx=isi;
        
        while(inorder[idx]!=preorder[psi])  idx++;
        
        int totalNumEleLSubT = idx-isi;
        
        node->left = buildTree_(preorder,psi+1,psi+totalNumEleLSubT ,inorder,isi,idx-1);
        node->right = buildTree_(preorder,psi+totalNumEleLSubT+1,pei ,inorder,idx+1,iei);
        
        return node;
        
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
          int n= preorder.size();
        return buildTree_(preorder,0,n-1,inorder,0,n-1);
    }
    
    //.....USING Map  .............
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        for(int i=0;i<preorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root = construct(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
private:
    TreeNode* construct(vector<int>&preorder, int preStart, int preEnd, vector<int> &inorder,int inStart, int inEnd, map<int,int> &mp){
        
        if(preStart>preEnd || inStart>inEnd) 
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int inRoot = mp[root->val];
        int numsLeft = inRoot-inStart;
        
        root->left = construct(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,mp);
        root->right = construct(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,mp);
        return root;
    }
};