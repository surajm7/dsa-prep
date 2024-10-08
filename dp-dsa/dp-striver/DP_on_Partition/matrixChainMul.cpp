#include <bits/stdc++.h> 
using namespace std;

 int matrixMultiplication(int N, int arr[])
    {
        // code here
        int dp[N][N];
        for(int i=1;i<N;i++) dp[i][i]=0;
        for(int i=N-1;i>=0;i--){
            for(int j =i+1;j<N;j++){
                int mini=INT_MAX;
                for(int k=i;k<=j-1;k++){
                    int steps=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                    mini= min(mini,steps);
                }
                dp[i][j]=mini;
            }
    
        }
        return dp[1][N-1];
        //   int t[N][N] = {0};
        
        // for(int i=1;i<N;i++) t[i][i] = 0;
        
        // for(int i=N-1;i>=0;i--){
        //     for(int j=i+1;j<N;j++){
        //         int mini = INT_MAX;
        //         for(int k=i;k<=j-1;k++){
        //             int ans = t[i][k] + t[k+1][j] + arr[i-1]*arr[k]*arr[j];
                    
        //             mini = min(mini, ans);
        //         }
        //         t[i][j] = mini;
        //     }
        // }
        // return t[1][N-1];
}


int solve(int i, int j, vector<int>&arr,vector<vector<int>>&dp){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mini=1e9;
    for(int k=i;k<j;k++){
        int steps=arr[i-1]*arr[k]*arr[j]+solve(i,k,arr,dp)+solve(k+1,j,arr,dp);
        if(steps<mini) mini=steps;
    }
    return dp[i][j]=mini;
}
 

int matrixMultiplication(vector<int>&arr,int N){
    // vector<vector<int>>dp(N,vector<int>(N,-1));
    // return solve(1,N-1,arr,dp);
    int dp[N][N];
    for(int i=1;i<N;i++) dp[i][i]=0;
    for(int i=N-1;i>=1;i--){
        for(int j =i+1;j<N;j++){
            int mini=1e9;
            for(int k=1;k<j;k++){
                int steps=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                if(steps<mini) mini=steps;
            }
            dp[i][j]=mini;
        }

    }
    return dp[1][N-1];
}