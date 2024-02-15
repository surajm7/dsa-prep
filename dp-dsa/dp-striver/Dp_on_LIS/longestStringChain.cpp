#include <bits/stdc++.h>
 using namespace std;

// TC:O(N^2*l)
bool checkPossible(string &s1,string &s2){
    if(s1.size()!=s2.size()+1)  return false;
    int first=0;
    int second=0;
    while(first<s1.size()){
        if(s1[first]==s2[second]){
            first++;
            second++;
        }else{
            first++;
        }
    }
    if(first==s1.size()&& second==s2.size())    return true;
    return false;
}


bool comp(string &s1 ,string &s2){
    return s1.size()<s2.size();
}


int longestStrongChain(vector<string>&arr,int n){
    sort(arr.begin(),arr.end(),comp);
    vector<int>dp(n,1);
    int maxi=1;
    int lastIndex=0;

    for(int i=0;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(checkPossible(arr[i],arr[prev])&& 1+dp[prev]>dp[i]){
                dp[i]=1+dp[prev];
            }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
        }
    }
    return maxi;
}
