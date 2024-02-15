#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
        bool isIsomorphic(string s, string t) {
            if (s.length() != t.length()) {
                return false;
            }
            unordered_map<char, char> mp; // map to store character mappings from s to t
            unordered_map<char, bool> used; // map to store which characters in t have been used
            for (int i = 0; i < s.length(); ++i) {
                char c1 = s[i], c2 = t[i];
                if (mp.find(c1) == mp.end()) {
                    // c1 is not yet mapped, so check if c2 is already used
                    if (used[c2]) {
                        return false;
                    }
                    // add c1 to map with c2 as its value and mark c2 as used
                    mp[c1] = c2;
                    used[c2] = true;
                } else if (mp[c1] != c2) {
                    // c1 is already mapped, so check if its value is c2
                    return false;
                }
            }
            return true;
       //  unordered_map<char, char> mp, mp2;
       //  for (int i=0; i<s.length(); ++i) {
       //      if (mp[s[i]] && mp[s[i]]!=t[i]) return false;
       //      if (mp2[t[i]] && mp2[t[i]]!=s[i]) return false;
       //      mp[s[i]]=t[i];
       //      mp2[t[i]]=s[i];
       //  }
       // return true;
    }
};