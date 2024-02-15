#include <bits/stdc++.h> 
using namespace std;

class Solution{
    public:
    int solve(int index,int buy,vector<int>&prices){
        if(index==prices.size()) return 0;

        int profit=0;
        if(buy){
            int buyIt=-prices[index]+solve(index+1,0,prices);
            int skipIt =0+solve(index+1,1,prices);
            profit=max(buyIt,skipIt);
        }else{
             int buyIt=prices[index]+solve(index+1,1,prices);
            int skipIt =0+solve(index+1,0,prices);
            profit=max(buyIt,skipIt);

        }
        return profit;
    }


     int solveMem(int index,int buy,vector<int>&prices,vector<vector<int>> &dp){
        if(index==prices.size()) return 0;

        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }

        int profit=0;
        if(buy){
            int buyIt=-prices[index]+solveMem(index+1,0,prices,dp);
            int skipIt =0+solveMem(index+1,1,prices,dp);
            profit=max(buyIt,skipIt);
        }else{
             int buyIt=prices[index]+solveMem(index+1,1,prices,dp);
            int skipIt =0+solveMem(index+1,0,prices,dp);
            profit=max(buyIt,skipIt);

        }
        return dp[index][buy]=profit;

    }

    
     int solveTab(vector<int>&prices){
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));

        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
            int profit=0;
            if(buy){
                int buyIt=-prices[index]+dp[index+1][0];
                int skipIt =0+dp[index+1][1];
                profit=max(buyIt,skipIt);
            }else{
                int buyIt=prices[index]+dp[index+1][1];
                int skipIt =0+dp[index+1][0];
                profit=max(buyIt,skipIt);
            }
            dp[index][buy]=profit;
            }
        }  
        return dp[1][0];

    }

      int solveSpaceOp(vector<int>&prices){
        int n=prices.size();
        vector<int> curr(2,0);
        vector<int> next(2,0);
       

        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
            int profit=0;
            if(buy){
                int buyIt=-prices[index]+next[0];
                int skipIt =0+next[1];
                profit=max(buyIt,skipIt);
            }else{
                int buyIt=prices[index]+next[1];
                int skipIt =0+next[0];
                profit=max(buyIt,skipIt);
            }
            curr[buy]=profit;
            }
            next=curr;
        }  
        return next[1];

    }

    int maxProfit(vector<int>&prices){
        // return solve(0,1,prices);
        int n =prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solveMem(0,1,prices,dp);
    }
};