#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        unordered_map<char, int> freq;
        int left = 0, right = 0, count = p.size();

        // calculate the frequency of characters in p
        for (auto c : p) {
            freq[c]++;
        }

        // use sliding window technique to find anagrams
        while (right < s.size()) {
            // move right pointer
            if (freq[s[right]] > 0) {
                count--;
            }
            freq[s[right]]--;
            right++;

            // if we have found an anagram, move left pointer
            if (count == 0) {
                result.push_back(left);
            }
            if (right - left == p.size()) {
                if (freq[s[left]] >= 0) {
                    count++;
                }
                freq[s[left]]++;
                left++;
            }
        }
        return result;
        
    }
};