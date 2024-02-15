#include <bits/stdc++.h>
 using namespace std;


int solve(int i ,int j,string&s,string &t,vector<vector<int>> dp){
    if(i<0||j<0)  return 0;

    if(dp[i][j]!= -1) return dp[i][j];

    if(s[i]==t[j]) return dp[i][j]=1+solve(i-1,j-1,s,t,dp);

    return dp[i][j]=max(solve(i-1,j,s,t,dp),solve(i,j-1,s,t,dp));
}


int lcs(string s, string t){
    int n =s.size();
    int m =t.size();

    vector<vector<int>> dp(n,vector<int>(m,-1));
    return solve(n-1,m-1,s,t,dp);
}


//shifting of the index

int solve(int i ,int j,string&s,string &t,vector<vector<int>> dp){
    if(i==0||j==0)  return 0;

    if(dp[i][j]!= -1) return dp[i][j];

    if(s[i-1]==t[j-1]) return dp[i][j]=1+solve(i-1,j-1,s,t,dp);

    return dp[i][j]=max(solve(i-1,j,s,t,dp),solve(i,j-1,s,t,dp));
}


int lcs(string s, string t){
    int n =s.size();
    int m =t.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return solve(n,m,s,t,dp);
}

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
    
    //to print lcs
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<< endl;
    }

    return dp[n][m];
}


int lcsSpaceOp(string s, string t){
    int n =s.size();
    int m =t.size();

    vector<int> prev(m+1,0),cur(m+1,0);
    for(int j=0;j<=m;j++) prev[j]=0;


    for(int i=1;i<=n;i++){
        for(int j= 1;j<=m;j++){
            if(s[i-1]==t[j-1]) cur[j]=1+prev[j-1];
            else cur[j]=max(prev[j],cur[j-1]);
        }
        prev=cur;
    }
    return cur[m];
}