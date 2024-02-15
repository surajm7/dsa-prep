#include <bits/stdc++.h>
using namespace std;


void topoSortDfs(int node, vector<bool> &visited, stack<int>&s, unordered_map<int,list<int>> &adj){
    visited[node] = 1;

    for(auto neighbour: adj[node]) {
        if(!visited [neighbour] )
            topoSortDfs(neighbour, visited, s, adj);
    } 
    //imp
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e){
    // create adj list
    unordered_map<int, list<int>>adj;

    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //call dfs toplogical sort util function for al components

    vector<bool> visited(v);
    stack<int>s;

    for(int i=0; i<v; i++) {
        if(!visited[i])
        topoSortDfs(i, visited, s, adj);
    }

    vector<int> ans;
    
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
     
    return ans;
}