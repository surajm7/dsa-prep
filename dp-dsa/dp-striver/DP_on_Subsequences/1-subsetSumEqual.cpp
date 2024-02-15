#include <bits/stdc++.h>
 using namespace std;


bool solve(int ind ,int target,vector<int>&arr){
    if(target==0) return true;
    if(ind==0) return (arr[0]==target);

    bool notTake=solve(ind-1,target,arr);
    bool take=false;
    if(arr[ind]<=target) take=solve(ind-1,target-arr[ind],arr);

    return notTake | take;
}


bool solveMem(int ind ,int target,vector<int>&arr,vector<vector<int>>&dp){
    if(target==0) return true;
    if(ind==0) return (arr[0]==target);
    if(dp[ind][target]!=-1) return dp[ind][target];

    bool notTake=solveMem(ind-1,target,arr,dp);
    bool take=false;
    if(arr[ind]<=target) take=solveMem(ind-1,target-arr[ind],arr,dp);

    return dp[ind][target]=notTake | take;
}

bool solveTab(int n ,int k,vector<int>&arr){
    vector<vector<int>>dp(n,vector<int>(k+1,0));

    vector<bool>prev(k+1,0),curr(k+1,0);
    prev[0]=curr[0]=true;
    prev[arr[0]]=true;

    for(int i =0;i<n;i++) dp[i][0]=true;
    dp[0][arr[0]]=true;
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){    
            bool notTake=dp[ind-1][target];
            bool take=false;
            if(arr[ind]<=target) take=dp[ind-1][target-arr[ind]];
            dp[ind][target]=take | notTake;
        }
    }
    return dp[n-1][k];
}

bool solveSpaceOpti(int n ,int k,vector<int>&arr){
   
    vector<bool>prev(k+1,0),curr(k+1,0);
    prev[0]=curr[0]=true;
    prev[arr[0]]=true;

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

bool subsetSumToK(int n ,int k,vector<int>&arr){
    // return solve(n-1,k,arr);
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return solveMem(n-1,k,arr,dp);
}