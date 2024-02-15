
#include <bits/stdc++.h> 
using namespace std;

int solveMem(int n ,vector<long long int> &dp){
    int M=1e9+7;
     if(n==1){
        return 0;
    }

    if(n==2){
        return 1;
    }

    dp[n] =(((n-1)%M)*((solveMem(n-1,dp)%M)+(solveMem(n-2,dp)%M))%M);

}

int solveTab(int n ){
     int M=1e9+7;
      vector<long long int> dp(n+1);
      dp[1]=0;
      dp[2]=1;

      for(int i =3;i<=n;i++){
        long long int first=dp[i-1]%M;
        long long int second=dp[i-2]%M;
        long long int sum=(first+second)%M;

        long long int ans =((i-1)*sum)%M;
        dp[i]=ans;
      }

      return dp[n];
}
int solveSpaceOpti(int n ){
    int M=1e9+7;
    vector<long long int> dp(n+1);
    long long int prev2=0;
    long long int prev1=1;

    for(int i =3;i<=n;i++){
        long long int first=prev1%M;
        long long int second=prev2%M;
        long long int sum=(prev1+prev2)%M;

        long long int ans =((i-1)*sum)%M;
        prev2 =prev1;
        prev1=ans;
    }

    return prev1;
}

long long int countDerangements(int n){
    // // base case
    // int M=1e9+7;

    // if(n==1){
    //     return 0;
    // }

    // if(n==2){
    //     return 1;
    // }

    // int ans =(((n-1)%M)*((countDerangements(n-1)%M)+(countDerangements(n-2)%M))%M);

    // vector<long long int> dp(n+1,-1);
    // return solveMem(n,dp);\

    return solveTab(n);
}