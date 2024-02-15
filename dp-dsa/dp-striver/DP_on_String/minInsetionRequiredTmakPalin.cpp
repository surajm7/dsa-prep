#include <bits/stdc++.h> 
using namespace std;

int lcsTab(string s, string t){
    int n =s.size();
    int m =t.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int j=0;j<=m;j++) dp[0][j]=0;
    for(int i=0;i<=m;i++) dp[i][0]=0;

    for(int i=1;i<=n;i++){
        for(int j= 1;j<=m;j++){
            if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<< endl;
    }
    return dp[n][m];
}

int longestPalindromicSubse(string s){
    string t =s;
    reverse(t.begin(),t.end());
    return lcsTab(s,t);
}

int minTnsertion(string &str){
    return str.size()-longestPalindromicSubse(str);
}
