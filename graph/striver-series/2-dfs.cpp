#include <bits/stdc++.h> 
using namespace std;

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node, vector<int> &ans,vector<int> &visited,vector<int> adj[])
    {
        ans.push_back(node);// enu process krna hun
        visited[node]=1;// hun ehe visited hogi a
        for(auto i:adj[node]) // edi adjecency list ch jiniya node payiann ny for each lga ky check kitia not visited recrsive call mardo usi neighbour node vsty
        {
            if(visited[i]==0)
            dfs(i,ans,visited,adj);
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans; // ans store krn vasty
        vector<int> visited(V,0);// to avoid infinite loop
        dfs(0,ans,visited,adj);// function call maro and alag fun is karky bnaya cuz recursion use hori hai
        return ans;
    }
   
};