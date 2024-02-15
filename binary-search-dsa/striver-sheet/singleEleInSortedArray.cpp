#include <bits/stdc++.h> 
using namespace std;


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low =0 , high=nums.size()-2;
        while(low<=high){
           int mid=(low+high)>>1;
            if(nums[mid]==nums[mid^1]){
                low=mid+1;
            }else{
                high=mid-1;
            }
           //in order to check for the left half
           //1st instance ->even index
           //2nd instance ->odd index , i need to check on the left if the 1st instance of that number is there or not
            
        }  
        return nums[low];
//         if(nums.size()==1)
//                 return nums[0];
        
//         int l=0, r=nums.size()-1, mid, num;
        
//         while(l < r){
//             mid = l+(r-l)/2;
//             num = (mid%2 == 0) ? mid+1 : mid-1;
//             if(nums[mid]==nums[num]) l = mid+1;
//             else r = mid;
//         }
//         return nums[l];
        
    }
};