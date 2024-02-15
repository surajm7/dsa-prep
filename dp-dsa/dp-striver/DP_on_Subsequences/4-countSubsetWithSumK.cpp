#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int solve(int ind ,int sum ,vector<int>&num){
            if(sum==0) return 1;
            if(ind==0) return num[0]==sum;

            int notTake =solve(ind-1,sum,num);
            int take=0;
            if(num[ind]<=sum){
                take=solve(ind-1,sum-num[ind],num);
            } 
            return notTake+take;
        }

        int solveMem(int ind ,int sum ,vector<int>&num, vector<vector<int>>&dp){
            if(sum==0) return 1;
            if(ind==0) return num[0]==sum;
            if(ind==0){
                if(sum==0 && arr[0]==0) return 2;
                if(sum==0 || sum==arr[0]) return 1;
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

         int solveTab(vector<int>&num,int tar){
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

                    dp[ind][sum]=notTake+take;
                }
            }
            return dp[n-1][tar];
        }


        int findWays(vector<int>&num,int tar){
           int n =num.size();
        //    return solve(n-1,tar,num) ;
            // vector<vector<int>>dp(n,vector<int>(tar+1,-1));
            // return solveMem(n-1,tar,num,dp);

            // vector<vector<int>>dp(n,vector<int>(tar+1,0));
            // for(int i=0;i<n;i++) dp[i][0]=1;
            // if(num[0]<=tar) dp[0][num[0]]=1;

            // for(int ind =1;ind<n;ind++){
            //     for(int sum =0;sum<=tar;sum++){
            //         int notTake =dp[ind-1][sum];
            //         int take=0;
            //         if(num[ind]<=sum) take=dp[ind-1][sum-num[ind]];

            //         dp[ind][sum]=notTake+take;
            //     }
            // }
            // return dp[n-1][tar];
            vector<int>prev(tar+1,0) ,cur(tar+1,0);
            if(num[0]==0) prev[0]=2;
            else prev[0]=1;
            //num[0]=0
            if(num[0]!=0 && num[0]<=tar) prev[num[0]]=1;

            for(int ind =1;ind<n;ind++){
                for(int sum =0;sum<=tar;sum++){
                    int notTake =prev[sum];
                    int take=0;
                    
                    if(num[ind]<=sum) take=prev[sum-num[ind]];

                    cur[sum]=notTake+take;
                }
                prev=cur;
            }
            return prev[tar];
        }
};