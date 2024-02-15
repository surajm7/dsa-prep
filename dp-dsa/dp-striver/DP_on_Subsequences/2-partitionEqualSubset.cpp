#include <bits/stdc++.h>
 using namespace std;

class Solution {
public:
    bool solveSubsetSumToK(int n ,int k,vector<int>&arr){
   
    vector<bool>prev(k+1,0),curr(k+1,0);
 
    prev[0]=curr[0]=true;
    if(arr[0]<=k) prev[arr[0]]=true;

    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){    
            bool notTake=prev[target];
            bool take=false;
            if(arr[ind]<=target) take=prev[target-arr[ind]];
            curr[target]=take| notTake;
        }
      prev=curr;  
    }
    return prev[k];
}

bool canPartition(vector<int>&arr){
    int n =arr.size();
    int toSum=0;
    for(int i=0;i<n;i++) toSum+=arr[i];
    if(toSum%2) return false;
    int target =toSum/2;

    return solveSubsetSumToK(n,target,arr);
}
//     bool canPartition(vector<int>& nums) {
// //         int sum = 0;
// //         int n = nums.size();
// //         for(int i = 0; i<n ; i++){
// //             sum += nums[i];
// //         }
// //         if(sum & 1) //if sum is odd
// //             return false;
// //         sum = sum/2;
// //         //dp[i][j] -> if sum 'i' is possible with elements from 0 to j-1
// //         //dp[sum+1][n]
// //         vector<vector<bool>> dp(sum+1,vector<bool>(n,false));
// //         //Sum=0 can be obtained using any number of elements
        
// // 		for(int i=0 ; i<n ; i++)
// //             dp[0][i] = true;
// //         //Sum>=0 can not be attained without any element
// //         for(int i=1 ; i<=sum ; i++)
// //             dp[i][0] = false;
        
// //         for(int i=1 ; i<=sum ; i++){
// //             for(int j=1 ; j<n ; j++){
// //                 dp[i][j] = dp[i][j-1];
// //                 if(i-nums[j-1] >= 0){
// //                     dp[i][j] = dp[i][j] || dp[i-nums[j-1]][j-1];
// //                 }
// //             }
// //         }
// //         return dp[sum][n-1];
        
//     }
};

bool solveSubsetSumToK(int n ,int k,vector<int>&arr){
   
    vector<bool>prev(k+1,0),curr(k+1,0);
    
    prev[0]=curr[0]=true;
    if(arr[0]<=k) prev[arr[0]]=true;

    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){    
            bool notTake=prev[target];
            bool take=false;
            if(arr[ind]<=target) take=prev[target-arr[ind]];
            curr[target]=take| notTake;
        }
      prev=curr;  
    }
    return prev[k];
}

bool canPartition(vector<int>&arr,int n){
    int toSum=0;
    for(int i=0;i<n;i++) toSum+=arr[i];
    if(toSum%2) return false;
    int target =toSum/2;

    return solveSubsetSumToK(n,target,arr);
}