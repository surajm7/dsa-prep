#include <bits/stdc++.h> 
using namespace std;

int searchInsert(vector<int>& nums, int target) {
        
    int s=0,e=nums.size()-1,ans=nums.size();

    while(s<=e){
        int m = s+(e-s)/2;
        if(nums[m]==target) return m;
        if(nums[m]<target) s=m+1;
        else{
            if(ans==nums.size() or nums[m]<nums[ans]) ans=m;
            e=m-1;
        }
    }

    return ans;
}
