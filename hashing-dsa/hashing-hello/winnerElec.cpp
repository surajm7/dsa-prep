#include <bits/stdc++.h> 
using namespace std;

vector<string> winner(string arr[] , int n){
    unordered_map<string , int> umap;
    for(int i=0;i<n;i++){
        umap[arr[i]]++;
    }

    string name="";
    int max_vote=0;

    for(auto itr=umap.begin();itr!=umap.end();itr++){
        string key = itr->first;
        int val =itr->second;

        if(val>max_vote){
            max_vote=val;
            name=key;
        }else if(val==max_vote){
            if(key<name){
                name=key;
            }
        }
    }

    vector<string> ans;
    ans.push_back(name);
    string temp=to_string(max_vote);
    ans.push_back(temp);
    
    return ans;
}