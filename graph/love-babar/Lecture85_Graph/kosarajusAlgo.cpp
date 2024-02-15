#include <bits/stdc++.h>
using namespace std;

int stronglyConnectedComponents(int v, vector<vector<int>> &edges){
    // adj
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++){
        edges[i][0];
        edges[i][1];

        int u =edges[i][0];
        int v =edges[i][0];

      
        adj[u].push_back(v);
    }

        // topo sort
        stack<int>st;

        unordered_map<int, bool> vis;
        for (int i = 0; i < v; i++){
            if (!vis[i]){
                dfs(i, vis, st, adj);
            }
        }

        //create a transpose graph
        unordered_map<int, list<int>> transpose;

        for(int i=0 ;i<v;i++){
            vis[i]=0;
            for(auto nbr: adj[i]) {
             transpose [nbr] .push_back(i);
            } 
        }

        //dfs call suing above ordering
        int count = 0;
        while(!st.empty()) {
            int top = st.top();
            st.pop();
            if(!vis[top]){
                count++;
                revdfs(top,vis,transpose);
            } 
        }
        return count;
}                
