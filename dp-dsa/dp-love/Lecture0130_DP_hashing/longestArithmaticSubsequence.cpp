#include <bits/stdc++.h> 
using namespace std;

class Solution{
    public:
    int longestSubsequence(vector<int>&arr,int differnce){

        unordered_map<int,int>dp;
        int ans=0;

        for(int i =0;i<arr.size();i++){
            int temp=arr[i]-differnce;
            int tempAns=0;

            //check answer exist for temp already or not
            if(dp.count(temp)){
                tempAns=dp[temp];
            }

            //current answer update
            dp[arr[i]]=1+tempAns;

            ans=max(ans,dp[arr[i]]);
        }
        return ans;
    }
    
    
};