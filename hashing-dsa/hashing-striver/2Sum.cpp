#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m {{nums[0], 0}}; // element, index of occurrence
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            int rem = target - nums[i];
            if(m.find(rem) != m.end()) {
                // required element exists in the array so far
                return {m[rem], i};
            }
            // update the current element in the map
            m.insert({nums[i], i});
        }
        return {};

        vector<int> ans;
        unordered_map<int,int>m;
        for(auto it: nums){
            if(m.find(target-nums[i])!=m.end()){
                ans.push_back(m[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            m[nums[i]]=i;
        }
        return ans;
    }
};