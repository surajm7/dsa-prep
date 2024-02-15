#include <bits/stdc++.h> 
using namespace std;

class Solution {
    public:
     int height( Node* node){
        //base case
        if(node == NULL) {
            return 0;
        }
        
        int left = height(node ->left);
        int right = height(node->right);
        
        int ans = max(left, right) + 1;
        return ans;
        
    }
    bool diameterBianryTree(TreeNode* root) {
            int diameter=0;
            height(root,diameter);
            return diameter;
        }
    private:    
       int height(TreeNode *node ,int&diameter) {
            if (!node) return 0;

            int lh= height(root->left,diameter);
            int rh =height(root->right,diameter);

            diameter=max(diameter,lh+rh);
            return 1+max(lh,rh);
       }    
    }
};    

