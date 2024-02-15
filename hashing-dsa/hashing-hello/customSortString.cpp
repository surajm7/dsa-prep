
#include <bits/stdc++.h> 
using namespace std;

string customSortString(string order , string str){
    map<char,int>mp;
    string ans ="";

    for(auto x: str)
        mp[x]++;

    for(auto x: order){
        if(mp.find(x)!=mp.end()){
            auto temp =mp.find(x);
            int count = temp->second;
            //c->5 || ccccc

            // for(int i =0;i<count;i++)
            //     ans+=x;

            string s(count,x);
            ans+=s;
            mp.erase(x);    
        }
    }  

    for(auto x: mp){
        string s(x.second ,x.first);
        ans+=s;
    }  
    return ans;
}