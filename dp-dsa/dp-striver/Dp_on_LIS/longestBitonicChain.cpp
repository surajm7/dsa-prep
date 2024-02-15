#include <bits/stdc++.h> 
using namespace std;

int longestSBitoniChain(vector<string>&arr,int n){
    
    vector<int>dp(n,1);
    for(int i=0;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(arr[prev]<arr[i] && 1+dp[prev]>dp[i]){
                dp[i]=1+dp[prev];
            }
        }
    }

    vector<int>dp2(n,1);
    for(int i=n-1;i>=0;i--){
        for(int prev=n-1;prev>i;prev--){
            if(arr[prev]<arr[i] && 1+dp2[prev]> dp2[i]){
                dp2[i]=1+dp2[prev];
            }
        }
    }

    int maxi=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi,dp[i]+dp2[i]-1);
    }
    return maxi;
}
