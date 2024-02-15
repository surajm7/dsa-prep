#include <bits/stdc++.h> 
using namespace std;

class Solution{
    private:
        // int solve(int ind,int buy ,vector<int>&prices){
        //     if(ind>=prices.size()) return 0;

        //     if(buy==1){
        //         return max(-prices[ind]+solve(ind+1,0,prices),0+solve(ind+1,1,prices));
        //     }
        //     //ind =n-1
        //     return max(prices[ind]+solve(ind+2,1,prices),0+solve(ind+1,0,prices));

        // }
        int solveMem(int ind,int buy ,vector<int>&prices,vector<vector<int>>&dp){
            if(ind>=prices.size()) return 0;
            if(dp[ind][buy]!=-1) return dp[ind][buy];


            if(buy==1){
              return dp[ind][buy]= max(-prices[ind]+solveMem(ind+1,0,prices,dp),0+solveMem(ind+1,1,prices,dp));
            }
            //ind =n-1
            return dp[ind][buy]= max(prices[ind]+solveMem(ind+2,1,prices,dp),0+solveMem(ind+1,0,prices,dp));

        }
    public:
        int maxProfit(vector<int>&prices){
        // return solve(0,1,prices);
        // int n=prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return solveMem(0,1,prices,dp);
      int n =prices.size();
            vector<vector<int>>dp(n+2,vector<int>(2,0));
            for(int ind=n-1;ind>=0;ind--){
                for(int buy=0;buy<=1;buy++){
                    if(buy==1){
                        dp[ind][buy]=max(-prices[ind]+dp[ind+1][0],0+dp[ind+1][1]);
                    }else{
                        dp[ind][buy]=max(prices[ind]+dp[ind+2][1],0+dp[ind+1][0]);
                    }

                }
            }
            return dp[0][1];
    }


};

