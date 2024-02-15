
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        //Approach 2
        int n =nums.size(),res=nums[0], left =1,right=1;
        
        for(int i =0;i<n;i++){
            left = left*nums[i];
            right =right*nums[n-i-1];
            res =max(res,max(left,right));
            
            if(left==0) left=1;
            if(right==0)right=1;
            
        }        
        return res;

        //Approach 1
        
        int ans=nums[0],max_prod =nums[0] ,min_prod =nums[0];
        
        for(int i= 1;i<nums.size();i++){
            if(nums[i]<0){
                swap(max_prod,min_prod);
            }
            
            max_prod =max(nums[i],max_prod*nums[i]);
            min_prod =min(nums[i],min_prod*nums[i]);
            
            ans=max(ans,max_prod);
        }
        
        return ans;
        
    }
};