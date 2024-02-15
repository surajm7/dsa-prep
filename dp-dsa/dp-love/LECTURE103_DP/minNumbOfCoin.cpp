#include <bits/stdc++.h> 
using namespace std;

int solveRec(vector<int>&num ,int x){

    //base case
    if(x==0)
        return 0;

    if(x<0){
        return INT_MAX;
    }    

    int mini =INT_MAX;
    for(int i =0;i<num.size();i++){
        int ans =solveRec(num,x-num[i]);
        if(ans!=INT_MAX){
            mini=min(mini,1+ans);
        }
    }
    
    return mini;

}



int solveMem(vector<int>&num ,int x,vector<int>&dp){

  //base case
  if(x==0){
    return 0;
  }

  if(x<0){
    return INT_MAX;
  }

  if(dp[x]!=-1){
    return dp[x];
  }

  int mini =INT_MAX;
  for(int i=0;i<num.size();i++){
    int ans = solveRec(num,x-num[i]);
    if(ans!=INT_MAX){
        mini =min(mini,1+ans);

    }
    dp[x]=mini;
    return mini;
  }

}

int solveTab(vector<int>&num ,int x){

    vector<int> dp(x+1,INT_MAX);
    dp[0]=0;

    for(int i =1;i<=x;i++){
        //i m trying to solve for every amount figure from 1 to x
        for(int j=0;j<num.size();j++){
            if(i-num[i] >=0 && dp[i=num[j]]!=INT_MAX){
                dp[i]=min(dp[i],1+dp[i-num[j]]);
            }
        }
    }

    if(dp[x]==INT_MAX){
        return -1;
    }

    return dp[x];

}

int minNumEle(vector<int> &num ,int x){
    // int ans =solveRec(num,x);
    // if(ans==INT_MAX)
    //     return -1;

    // return ans;

    // vector<int> dp(x+1,-1);
    // int ans =solvMem(num,x,dp);

    // if(ans==INT_MAX)
    //     return -1;
    // else
    //     return ans;

    return solveTab(num,x);


}