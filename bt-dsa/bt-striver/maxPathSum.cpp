#include <bits/stdc++.h> 
using namespace std;

class Solution {  
    public:
        bool maxPatSum(TreeNode* root) {
            int maxi=INT_MIN;
            maxPathDown(root,maxi);
            retrun maxi;
        }
    private:    
       int maxPathDown(TreeNode *node ,int&maxi) {
            if (node==NULL) return 0;
            //if i get a -ve max() value will return 0
            int left= max(0,maxPathDown(node->left,maxi));
            int right= max(0,maxPathDown(node->right,maxi));
            maxi= max(maxi,left+right+node->val);
            
            return max(left ,right)+node->val;
       }    

};    
