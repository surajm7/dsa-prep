#include <bits/stdc++.h>
 using namespace std;


// int solve(int i ,int j ,string &pattern ,string &text,vector<vector<int>>&dp){
//     if(i<0&&j<0) return true;
//     if(i<0&&j>=0) return false;
//     if(j<0 && i>=0){
//         for(int ii=0;ii<=i;ii++){
//             if(pattern[ii]!='*') return false;
//         }
//         return true;
//     }
//     if(dp[i][j]!=-1) return dp[i][j];

//     if(pattern[i]==text[j] || pattern[i]=='?'){
//         return solve(i-1,j-1,pattern,text,dp);
//     }
//     if(pattern[i]=='*'){
//         return solve(i-1,j,pattern,text,dp) | solve(i, j-1,pattern,text,dp);
//     }
//     return dp[i][j]=false;
// }


// int wildCarDMatching(string pattern, string text){
//     int n=pattern.size();
//     int m=text.size();

//     vector<vector<int>> dp(n,vector<int>(m,-1));
//     return solve(n-1,m-1,pattern,text,dp);
// }

//shifting of index
int solve(int i ,int j ,string &pattern ,string &text,vector<vector<int>>&dp){
    if(i==0&&j==0) return true;
    if(i==0&&j>0) return false;
    if(j==0 && i>0){
        for(int ii=0;ii<=i;ii++){
            if(pattern[ii-1]!='*') return false;
        }
        return true;
    }
    if(dp[i][j]!=-1) return dp[i][j];

    if(pattern[i-1]==text[j-1] || pattern[i]=='?'){
        return solve(i-1,j-1,pattern,text,dp);
    }
    if(pattern[i]=='*'){
        return solve(i-1,j,pattern,text,dp) | solve(i, j-1,pattern,text,dp);
    }
    return dp[i][j]=false;
}


// int wildCarDMatching(string pattern, string text){
//     int n=pattern.size();
//     int m=text.size();

//     vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
//     return solve(n-1,m-1,pattern,text,dp);
// }



int wildCarDMatchingTab(string pattern, string text){
    int n=pattern.size();
    int m=text.size();

    vector<vector<bool>> dp(n+1,vector<int>(m+1,false));
    dp[0][0]=true;
    for(int j=1;j<=m;j++){
        dp[0][j]=false;
    }

    for(int i =1;i<=n;i++){
        int flag=true;
        for(int ii=1;ii<=i;ii++){
            if(pattern[ii-1]!='*'){
                flag=false;
                break;
            }
        }
        dp[i][0]=flag;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(pattern[i-1]==text[j-1] || pattern[i-1]=='?'){
                dp[i][j]=dp[i-1][j-1];
            }else if(pattern[i-1]=='*'){
                dp[i][j]=dp[i-1][j] |dp[i][j-1];
            }else{
                dp[i][j]=false;
            }
        }
    }
    return dp[n][m];
}


bool isAllStars(string & S1, int i) {

  // S1 is taken in 1-based indexing
  for (int j = 1; j <= i; j++) {
    if (S1[j - 1] != '*')
      return false;
  }
  return true;
}

bool wildcardMatchingSpaceOp(string & S1, string & S2) {

  int n = S1.size();
  int m = S2.size();

  vector < bool > prev(m + 1, false);
  vector < bool > cur(m + 1, false);

  prev[0] = true;

  for (int i = 1; i <= n; i++) {
    cur[0] = isAllStars(S1, i);
    for (int j = 1; j <= m; j++) {

      if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
        cur[j] = prev[j - 1];

      else {
        if (S1[i - 1] == '*')
          cur[j] = prev[j] || cur[j - 1];

        else cur[j] = false;
      }
    }
    prev = cur;
  }

  return prev[m];

}
