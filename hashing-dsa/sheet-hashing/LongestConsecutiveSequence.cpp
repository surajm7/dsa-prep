/*
    Problem Link: https://leetcode.com/problems/longest-consecutive-sequence/
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
//brute force
          if(nums.size() == 0 ){
            return 0;
        }
        
        sort(nums.begin(),nums.end());
        
        int ans = 1;
        int prev = nums[0];
        int cur = 1;
        
        for(int i = 1;i < nums.size();i++){
            if(nums[i] == prev+1){
                cur++;
            }
            else if(nums[i] != prev){
                cur = 1;
            }
            prev = nums[i];
            ans = max(ans, cur);
        }
        return ans; 

        int max_len = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        
        for(int x : s) {
            // x will be the first number of the sequence
            // if x - 1 exists then current x is already a part of the sequence.
            if(s.find(x - 1) != s.end())
                continue;
            int cur_len = 1;
            while(s.find(++x) != s.end())
                cur_len++;
            
            max_len = max(max_len, cur_len);
        }
        return max_len;

        int longestConsecutive(vector<int>& nums) {
            unordered_set<int> s(begin(nums), end(nums));
            int longest = 0;
            for(auto& num : s) {
                if(s.count(num - 1)) continue;
                int j = 1;
                while(s.count(num + j)) j++;
                longest = max(longest, j);
            }
                return longest;
        }


        set<int>hashSet;
        for (int num: nums){
            hashSet.insert(num);
        }
        int longestStreak = 0;
        for(int num: nums){
            if (!hashSet.count(num - 1)) {
            int currentNum = num;
            int currentStreak = 1;

            while (hashSet.count(currentNum + 1)) {
                currentNum += 1;
                currentStreak += 1;
            }

            longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};