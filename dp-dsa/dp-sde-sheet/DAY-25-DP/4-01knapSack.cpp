#include <bits/stdc++.h> 
using namespace std;

int solve(int ind ,int W ,vector<int> &wt ,vector<int> &val){
    if(ind==0){
        if(wt[0]<=W) return val[0];
        return 0;
    }

    int notTake =0+ solve(ind-1,W,wt,val);
    int take =INT_MIN;
    if(wt[ind]<=W){
        take=val[ind]+solve(ind-1,W-wt[ind],wt,val);
    }
    return max(take,notTake);
}


int solveMem(int ind ,int W ,vector<int> &wt ,vector<int> &val,vector<vector<int>>&dp){
    if(ind==0){
        if(wt[0]<=W) return val[0];
        return 0;
    }

    if(dp[ind][W]!=-1) return dp[ind][W];

    int notTake =0+ solveMem(ind-1,W,wt,val,dp);
    int take =INT_MIN;
    if(wt[ind]<=W){
        take=val[ind]+solveMem(ind-1,W-wt[ind],wt,val,dp);
    }
    return dp[ind][W]=max(take,notTake);
}


int knapsackTab(vector<int> wt,vector<int> val,int n,int maxWeight){
    // return solve(n-1,maxWeight,weight,value);
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
    for(int W=wt[0];W<=maxWeight;W++) dp[0][W]=val[0];

    for(int ind=1;ind<n;ind++){
        for(int W=0;W<=maxWeight;W++){
            int notTake=0+dp[ind-1][W];
            int take=INT_MIN;
            if(wt[ind]<=W){
                take=val[ind]+dp[ind-1][W-wt[ind]];
            }
            dp[ind][W]=max(take,notTake);
        }
    }
    return dp[n-1][maxWeight];
}

int knapsackSapceOp(vector<int> wt,vector<int> val,int n,int maxWeight){
    // return solve(n-1,maxWeight,weight,value);
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
    vector<int> prev(maxWeight+1,0),cur(maxWeight+1,0);

    for(int W=wt[0];W<=maxWeight;W++) prev[W]=val[0];

    for(int ind=1;ind<n;ind++){
        for(int W=0;W<=maxWeight;W++){
            int notTake=0+prev[W];
            int take=INT_MIN;
            if(wt[ind]<=W){
                take=val[ind]+prev[W-wt[ind]];
            }
            dp[ind][W]=max(take,notTake);
        }
        prev=cur;
    }
    return prev[maxWeight];
}

int knapsack(vector<int> weight,vector<int> value,int n,int maxWeight){
    // return solve(n-1,maxWeight,weight,value);
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
    return solveMem(n-1,maxWeight,weight,value,dp);
}
