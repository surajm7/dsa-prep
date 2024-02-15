#include <bits/stdc++.h> 
using namespace std;
 
class Solution {
private:
    // Function to detect cycle in an undirected graph.
    bool dfs(int node  , vector<int> adj[],int vis[] , int dfsVis[]) {
      vis[node]=1;
      dfsVis[node]=1;
      for(auto adjacentNode : adj[node]){
        if(!vis[adjacentNode]){
            if(dfs(adjacentNode , adj ,vis,dfsVis)){
                return true;
            }
        }else if(dfsVis[adjacentNode]) 
                return true;
      }
      dfsVis[node]=0;
      return false;
    }  
public:
    bool isCycle(int N, vector<int>adj[]){
        int vis[N] ,dfsVis[N];
        memset(vis,0,sizeof vis);
        memset(dfsVis ,0,sizeof dfsVis);

        for(int i=0;i<N;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,dfsVis))
                     return true;
            }
        }
        return false;
    }  
};


