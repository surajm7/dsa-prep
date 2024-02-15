#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int f(int i , int j1 , int j2 ,int r ,int c,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
        if(j1<0 || j2<0 || j1>=c || j2>=c){
            return -1e8;
        }
        if(i==r-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }

        //explore all paths of alice and bob simultan
        int maxi=-1e8;
        for(int dj1=-1;dj1<=+1;dj1++){
            for(int dj2=-1;dj2<=+1;dj2++){
                int value =0;
                if(j1==j2) value=grid[i][j1];
                else value =grid[i][j1]+grid[i][j2];
                value+=f(i+1,j1+dj1,j2+dj2,r,c,grid,dp);
                maxi=max(maxi,value);
            }
        }
        return maxi;
    }


    int cherryPickup(vector<vector<int>>& grid){
        int r =grid.size() , c=grid[0].size();
        // return f(0,0,c-1,r,c,grid,dp);
        vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        return f(0,0,c-1,r,c,grid,dp);
    }

    class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    
        for(int j1=0; j1<m; j1++) {
            for(int j2=0; j2<m; j2++) {
                if(j1 == j2) dp[n - 1][j1][j2] = grid[n - 1][j1];
                else  dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }

        for(int i=n-2; i>=0; i--) {
            for(int j1=0; j1<m; j1++) {
                for(int j2=0; j2<m; j2++) {
                    int mx = 0;
                    for(int k=-1; k<=1; k++) {
                        for(int p=-1; p<=1; p++) {
                            int x = j1 + k, y = j2 + p;
                            if(x >= 0 && x < m && y >= 0 && y < m) {
                                if(j1 == j2) mx = max(mx, grid[i][j1] + dp[i + 1][x][y]);
                                else mx = max(mx, grid[i][j1] + grid[i][j2] + dp[i + 1][x][y]);
                            }
                        }
                    }
                    dp[i][j1][j2] = mx;
                }
            }
        }
        return dp[0][0][m - 1];
    }
};
    int cherryPickup(vector<vector<int>>& grid){
        int n =grid.size() , m=grid[0].size();
        // return f(0,0,c-1,r,c,grid,dp);
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(m,0)));
        for(int j1 =0 ;j1<n;j1++){
            for(int j2=0 ;j2<n;j2++){
                if(j1==j2) dp[n-1][j1][j2]=grid[n-1][j1];
                else dp[n-1][j1][j2] =grid[n-1][j1]+grid[n-1][j2];
            }
        }

        for(int i=n-2;i>=0;i--){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                     int maxi=-1e8;
                    for(int dj1=-1;dj1<=+1;dj1++){
                        for(int dj2=-1;dj2<=+1;dj2++){
                            int value =0;
                            if(j1==j2) value=grid[i][j1];
                            else value =grid[i][j1]+grid[i][j2];
                            if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m)
                                value+=dp[i+1][j1+dj1][j2+dj2];
                            else
                                value+=-1e8;    
                            maxi=max(maxi,value);
                        }
                    }    
                
                 return dp[i][j1][j2]=maxi;
                }
            }
        }
       return dp[0][0][m-1];
    }

    
};