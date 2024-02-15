#include <bits/stdc++.h> 
using namespace std;


int solve(int n ,vector<int>&days,vector<int> &cost,int index){
    //BASE CASE
    if(index >=n)  return 0;

    //1 day pass
    int option1 =cost[0] +solve(n,days,cost,index+1);

    int i;
    //7 Day pass
    for(i=index;i<n&&days[i]<days[index]+7;i++);

    int option2 =cost[1]+solve(n,days,cost,i);

     //7 Day pass
    for(i=index;i<n&&days[i]<days[index]+30;i++);

    int option3 =cost[2]+solve(n,days,cost,i);

    return min(option1,min(option2,option3));
}

int solveMem(int n ,vector<int>&days,vector<int> &cost,int index, vector<int>&dp){
    //BASE CASE
    if(index >=n)  return 0;

    if(dp[index]!=-1){
        return dp[index];
    }

    //1 day pass
    int option1 =cost[0] +solveMem(n,days,cost,index+1,dp);

    int i;
    //7 Day pass
    for(i=index;i<n&&days[i]<days[index]+7;i++);

    int option2 =cost[1]+solveMem(n,days,cost,i,dp);

     //7 Day pass
    for(i=index;i<n&&days[i]<days[index]+30;i++);

    int option3 =cost[2]+solveMem(n,days,cost,i,dp);

    dp[index] =min(option1,min(option2,option3));

    return dp[index];
}

int solveTab(int n ,vector<int>&days,vector<int> &cost){
    vector<int>dp(n+1,INT_MAX);
    dp[n]=0;

    for(int k=n-1;k>=0;k--){
        //1 day pass
        int option1 =cost[0] +dp[k+1];

        int i;
        //7 Day pass
        for(i=k;i<n&&days[i]<days[k]+7;i++);

        int option2 =cost[1]+dp[i];

        //7 Day pass
        for(i=k;i<n&&days[i]<days[k]+30;i++);

        int option3 =cost[2]+dp[i];

        dp[k] =min(option1,min(option2,option3));
    }
    
    return dp[0];
}


 int minimumCoins(int n ,vector<int>days,vector<int> cost){
    // return solve(n,days,cost,0);
    // vector<int>dp(n+1,-1);
    // return solveMem(n,days,cost,0,dp);
    solveTab(n,days,cost);
 }