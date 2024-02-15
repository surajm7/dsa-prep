#include <bits/stdc++.h> 
using namespace std;

int solve(int ind ,vector<int>&heights,vector<int>&dp){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int left =solve(ind-1,heights,dp)+abs(heights[ind]-heights[ind-1]);
    int right=INT_MAX;
    if(ind >1) right=solve(ind-2,heights,dp)+abs(heights[ind]-heights[ind-2]);
    return dp[ind]=min(left,right);
}


int frogJump(int n , vector<int>&heights){
     vector<int> dp(n+1,-1);
     return solve(n-1,heights,dp);
}

int frogJumpTab(int n , vector<int>&heights){
     vector<int> dp(n,0);
     dp[0]=0;
     for(int i=1;i<n;i++){
        int fs=dp[i-1]+abs(heights[i]-heights[i-1]);
        int ss=INT_MAX;
        if(i>1) ss=dp[i-2]+abs(heights[i]-heights[i-1]);

        dp[i]=min(fs,ss);
        return dp[n-1];
     }
}


int frogJumpTabSpacep(int n , vector<int>&heights){
    //  vector<int> dp(n,0);
    //  dp[0]=0;
    int prev=0;
    int prev2=0;
    for(int i=1;i<n;i++){
        int fs=prev+abs(heights[i]-heights[i-1]);
        int ss=INT_MAX;
        if(i>1) ss=prev2+abs(heights[i]-heights[i-1]);

        int curri=min(fs,ss);
        prev2=prev;
        prev=curri;
        return prev;
     }
}