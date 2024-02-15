#include <bits/stdc++.h>
 using namespace std;

class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>&grid){
        int n=grid.size() ;
        int m =grid[0].size();
        
        if(i<0 || i>=n|| j<0 || j>=m || grid[i][j]=='0')
            return;
        
        grid[i][j] = '0';
        
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int cnt = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};