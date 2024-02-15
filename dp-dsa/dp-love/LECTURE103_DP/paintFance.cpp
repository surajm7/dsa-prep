#include <bits/stdc++.h> 
using namespace std;

int M=1e9+7;

int add(int a, int b){
    return(a%M+b%M)%M;
}

int mul(int a,int b){
    return ((a%M)*(b%M))%M;
}


int solve(int n ,int k){
    //base case 
    if(n==1)
        return k;
    if(n==2)
        return add(k,mul(k,k-1));

    int ans =add(mul(solve(n-2,k),k-1),mul(solve(n-1,k),k-1));
    return ans;        
}


int solveMem(int n ,int k,vector<int> &dp){
    //base case 
    if(n==1)
        return k;
    if(n==2)
        return add(k,mul(k,k-1));
    
    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n]=add(mul(solve(n-2,k),k-1),mul(solve(n-1,k),k-1));
    return dp[n];        
}

int solveTab(int n ,int k,vector<int> &dp){
      vector<int> dp(n+1,0);
      dp[1]=k;
      dp[2]=add(k,mul(k,k-1));  

      for(int i=3;i<=n;i++){
        dp[i]=add(mul(dp[i-2],k-1),mul(dp[i-1],k-1));
      } 

      return dp[n]; 
}

int solveSpaceOp(int n ,int k){
    
     int prev2 =k;
      int prev1 =add(k,mul(k,k-1));  

      for(int i=3;i<=n;i++){
       int  ans=add(mul(prev2,k-1),mul(prev1,k-1));
       prev2=prev1;
       prev1=ans;
      } 

      return prev1; 
}

int numberOfWays(int n, int k){
    // return solve(n,k);
    // vector<int> dp(n+1,-1);
    // return solveMem(n,k,dp);

    return solveSpaceOp(n,k);

}