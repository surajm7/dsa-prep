#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
            
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int>mp;
        
        for(int i=0;i<nums.size();i++)
             mp[nums[i]]++;      
        
        for (auto i : mp){
          pq.push(make_pair(i.second, i.first));
        }    
        
        vector<int> ans;
        
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
             return ans;
//         unordered_map<int, int> freq;
//         for (auto num : nums) 
//             freq[num]++;
        
//         priority_queue<pair<int, int>> pq;
//         for (auto [a, b] : freq)
//             pq.push({b, a});
        
//         vector<int> res;
//         while (k) {
//             res.push_back(pq.top().second);
//             pq.pop();
//             k--;
//         }    
//         return res;     
    }
};
