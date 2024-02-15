#include <bits/stdc++.h>
 using namespace std;


int f(int i ,int j ,vector<vector<int> > & triangle ,vector<vector<int> >&dp){
   int n=triangle.size();
    if(i==n-1){
        return triangle[n-1][j];
    }

    int d =triangle[i][j]+f(i+1,j,triangle,n);
    int dg =triangle[i][j]+f(i+1,j+1,triangle,n);
    return min(d,dg);
}

  int minimumTotal(vector<vector<int> >& triangle) {
    int n=triangle.size();
    vector<vector<int> >dp(n,vector<int>(n,-1));
    return f(0,0,triangle,n,dp);
}

  int minimumTotalTab(vector<vector<int> >& triangle) {
    int n=triangle.size();
    vector<vector<int> >dp(n,vector<int>(n,-1));
    
    for(int j=0;j<n;j++) dp[n-1][j]=triangle[n-1][j];
    for(int i =n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int d =triangle[i][j]+dp[i+1][j];
            int dg =triangle[i][j]+dp[i+1][j+1];
            dp[i][j]=min(d,dg);
        }
    }
    return dp[0][0];
}

  int minimumTotalSO(vector<vector<int> >& triangle) {
    int n=triangle.size();
    vector<int>front(n,0) , cur(n,0);
    
    for(int j=0;j<n;j++) front[j]=triangle[n-1][j];
    for(int i =n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int d =triangle[i][j]+front[j];
            int dg =triangle[i][j]+front[j+1];
           cur[j]=min(d,dg);
        }
        front=cur;
    }
    return front[0];
}