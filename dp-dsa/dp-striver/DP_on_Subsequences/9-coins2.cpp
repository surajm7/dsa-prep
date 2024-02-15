#include <bits/stdc++.h> 
using namespace std;

 int change(int amount, vector<int>& coins){
        int n = coins.size();
        vector<vector<int>> dp(n + 1 , vector<int> (amount + 1));
        for(int i = 0 ; i <= n ; i++){
            dp[i][0] = 1;
        }
        for(int i = 1 ; i <= amount ; i++){
            dp[0][i] = 0;
        }
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= amount ; j++){
                dp[i][j] += dp[i-1][j];
                if(j >= coins[i-1])
                    dp[i][j] += dp[i][j - coins[i-1]];
            }
        }
        
        return dp[n][amount];
    }
    
long solve(int ind ,int T ,int *a){
    if(ind==0){
        return (T%a[0]==0);
    }

    long notTake=solve(ind-1,T,a);
    long take=0;
    if(a[ind]<=T) take=solve(ind,T-a[ind],a);
    return take+notTake;
}

long solveMem(int ind ,int T ,int *a,vector<vector<long>>&dp){
    if(ind==0){
        return (T%a[0]==0);
    }
    if(dp[ind][T]!=-1) return dp[ind][T];

    long notTake=solveMem(ind-1,T,a,dp);
    long take=0;
    if(a[ind]<=T) take=solveMem(ind,T-a[ind],a,dp);
    return dp[ind][T]=take+notTake;
}


long countWaysToMakeChange(int *denominations,int n,int value){

    // return solve(n-1,value,denominations);
    vector<vector<long>> dp(n,vector<int>(value+1,-1));
    return solveMem(n-1,value,denominations,dp);

}

long countWaysToMakeChangeTab(int *denominations,int n,int value){

    // return solve(n-1,value,denominations);
    vector<vector<long>> dp(n,vector<int>(value+1,0));

    for(int T=0;T<=value;T++){
        dp[0][T]=(T%a[0]==0);
    }

    for(int ind=1;ind<n;ind++){
        for(int T=0;T<=value;T++){
            long notTake=dp[ind-1][T];
            long take=0;
            if(a[ind]<=T) take=dp[ind][T-a[ind]];
            dp[ind][T]=take+notTake;
        }
    }
    return dp[ind-1][value];
}


long countWaysToMakeChangespaceOp(int *denominations,int n,int value){

    // return solve(n-1,value,denominations);
    vector<int>prev(value+1,0),cur(value+1,0);


    for(int T=0;T<=value;T++){
        prev[T]=(T%a[0]==0);
    }

    for(int ind=1;ind<n;ind++){
        for(int T=0;T<=value;T++){
            long notTake=prev[T];
            long take=0;
            if(a[ind]<=T) take=cur[T-a[ind]];
           cur[T]=take+notTake;
        }
        prev=cur;
    }
    return prev[value];
}