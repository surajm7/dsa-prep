#include <bits/stdc++.h>
using namespace std;

int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int new_target = (sum + target)/2;
        //if sum is less than target or numerator of new_target is odd then there will be no ways hence we will return 0
        if(sum < target || (sum + target)%2 != 0 || new_target < 0)
            return 0;
        
        vector<int>dp(new_target+1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++)
            for(int j = new_target; j >= nums[i]; j--)
                dp[j] += dp[j-nums[i]];
        return dp[new_target];
    }

int solveMem(int ind, int sum, vector<int> &num, vector<vector<int>> &dp)
{
    if (sum == 0)
        return 1;
    if (ind == 0)
        return num[0] == sum;
    if (ind == 0)
    {
        if (sum == 0 && arr[0] == 0)
            return 2;
        if(sum == 0 || sum == arr[0]) return 1;
        return 0;
    }
    if (dp[ind][sum] != -1)
        return dp[ind][sum];

    int notTake = solveMem(ind - 1, sum, num, dp);
    int take = 0;
    if (num[ind] <= sum)
    {
        take = solveMem(ind - 1, sum - num[ind], num, dp);
    }
    return dp[ind][sum] = notTake + take;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
    if (num[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;
    // num[0]=0
    if (num[0] != 0 && num[0] <= tar)
        dp[0][num[0]] = 1;

    for (int ind = 1; ind < n; ind++)
    {
        for (int sum = 0; sum <= tar; sum++)
        {
            int notTake = dp[ind - 1][sum];
            int take = 0;
            if (num[ind] <= sum)
                take = dp[ind - 1][sum - num[ind]];

            dp[ind][sum] = (notTake + take);
        }
    }
    return dp[n - 1][tar];
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int totSum = 0;
    for (auto &it : arr)
        totSum += it;
    if (totSum - d < 0 || (totSum - d) % 2)
        return false;
    return findWays(arr, (totSum - d) / 2);
}

int targetSum(int n, int target, vector<int> &arr)
{
    return countPartitions(n, target, arr);
}
