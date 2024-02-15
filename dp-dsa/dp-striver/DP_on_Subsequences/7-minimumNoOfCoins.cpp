#include <bits/stdc++.h>
 using namespace std;


int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++) {
            for(int j = 0; j < n; j++) {
                if(i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX)
                    dp[i] = min(dp[i], 1+dp[i-coins[j]]);
            }
        }
        return dp[amount] == INT_MAX? -1: dp[amount];
    }

int solve(int ind ,int T,vector<int>&nums){
    if(ind==0){
        if(T%nums[0]==0) return T/ nums[0];
        return 1e9;
    }


    int notTake=0+solve(ind-1,T,nums);
    int take=INT_MAX;
    if(nums[ind]<=T){
        take=1+solve(ind,T-nums[ind],nums);
    }
    return min(take,notTake);
}

int solveMem(int ind ,int T,vector<int>&nums, vector<vector<int>> &dp){
    if(ind==0){
        if(T%nums[0]==0) return T/ nums[0];
        return 1e9;
    }
    if(dp[ind][T]!=-1) return dp[ind][T];

    int notTake=0+solveMem(ind-1,T,nums,dp);
    int take=INT_MAX;
    if(nums[ind]<=T){
        take=1+solveMem(ind,T-nums[ind],nums,dp);
    }

    return dp[ind][T]=min(take,notTake);
}



int minimumElementsSpaceOp(vector<int>&nums,int target){
    int n=nums.size();
    
    vector<int> prev(target+1,0),cur(target+1,0);

    for(int T=0;T<=target;T++){
        if(T% nums[0]==0) prev[T]=T/nums[0];
        else prev[T]=1e9;
    }
   
     for(int ind=1;ind<n;ind++){
        for(int T=0;T<=target;T++){
            int notTake=0+prev[T];
            int take=INT_MAX;
            if(nums[ind]<=T){
                take=1+cur[T-nums[ind]];
            }
            cur[T]=min(take,notTake);
        }
        prev=cur;
     }

    int ans=prev[target];
    if(ans>=1e9) return -1;
    return ans;
}


int minimumElementsTab(vector<int>&nums,int target){
    int n=nums.size();
    
    vector<vector<int>> dp(n,vector<int>(target+1,0));
    for(int T=0;T<=target;T++){
        if(T% nums[0]==0) dp[0][T]=T/nums[0];
        else dp[0][T]=1e9;
    }
   
    for(int ind=1;ind<n;ind++){
        for(int T=0;T<=target;T++){
            int notTake=0+dp[ind-1][T];
            int take=INT_MAX;
            if(nums[ind]<=T){
                take=1+dp[ind][T-nums[ind]];
            }
            dp[ind][T]=min(take,notTake);
        }
    }

    int ans=dp[n-1][target];
    if(ans>=1e9) return -1;
    return ans;
}

int minimumElements(vector<int>&num,int target){
    int n=num.size();
    // return solve(n-1,target,num);
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    int ans=solveMem(n-1,target,num,dp);
    if(ans>=1e9) return -1;
    return ans;
}