#include <bits/stdc++.h> 
using namespace std;


vector<vector<string>> groupAnagrams(vector<string>&str){

    vector<vector<string>> ans;
    unordered_map<string,vector<string>>umap;

    for(auto x: str){
        string temp =x;
        sort(x.begin(),x.end());
        umap[x].push_back(temp);
    }
    // for(auto itr=umap.begin();itr!=umap.end();itr++){

    // }

    for(auto x:umap){
        vector<string>temp =x.second;
        ans.push_back(temp);
    }
    return ans;
}