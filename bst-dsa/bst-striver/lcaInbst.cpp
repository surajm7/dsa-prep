#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        else return root;
    }
    
    //iterative
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (p->val < root->val && q->val < root->val) root = root->left;
            else if (p->val > root->val && q->val > root->val) root = root->right;
            else return root;
        }
        return root;
    }


   // TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
   // {
   //    if (root == NULL)
   //    {
   //       return NULL;
   //    }
   //    while (root != NULL)
   //    {
   //       if (root->val < P->val && root->val < Q->data)
   //          root = root->right;

   //       else if (root->val > P->val && root->val > Q->data)
   //          root = root->left;
   //       else
   //       {
   //          return root;
   //       }
   //    }

   //    if (root->val < P->val && root->val < Q->val)
   //       return LCAinBST(root->right, P, Q);

   //    if (root->val > P->val && root->val > Q->val)
   //       return LCAinBST(root->left, P, Q);

   //    return root;
   // }
};