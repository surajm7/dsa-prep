#include <bits/stdc++.h>
 using namespace std;

class Solution{
    public:
    int mod=(int)(1e9+7)
       
        int solveMem(int ind ,int sum ,vector<int>&num, vector<vector<int>>&dp){
            // if(sum==0) return 1;
            if(ind==0) return num[0]==sum;
            if(ind==0){
                if(sum==0 && arr[0]==0) return 2;
                i(sum==0 || sum==arr[0]) return 1;
                return 0;
            }
            if(dp[ind][sum]!=-1) return dp[ind][sum];

            int notTake =solveMem(ind-1,sum,num,dp);
            int take=0;
            if(num[ind]<=sum){
                take=solveMem(ind-1,sum-num[ind],num,dp);
            }  
            return dp[ind][sum]=notTake+take;
        }

         int findWays(vector<int>&num,int tar){
            int n =num.size();
            vector<vector<int>>dp(n,vector<int>(tar+1,0));
            if(num[0]==0) dp[0][0]=2;
            else dp[0][0]=1;
            //num[0]=0
            if(num[0]!=0 && num[0]<=tar) dp[0][num[0]]=1;

            for(int ind =1;ind<n;ind++){
                for(int sum =0;sum<=tar;sum++){
                    int notTake =dp[ind-1][sum];
                    int take=0;
                    if(num[ind]<=sum) take=dp[ind-1][sum-num[ind]];

                    dp[ind][sum]=(notTake+take)%mod;
                }
            }
            return dp[n-1][tar];
        }

        int countPartitions(int n,ind,vector<int>&arr){
            int totSum=0;
            for(auto &it:arr) totSum+=it;
            if(totSum-d<0 ||(totSum-d)%2) return false;
            return findWays(arr,(totSum-d)/2);
        }
};