#include <bits/stdc++.h>
 using namespace std;

vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.
    vector<int>ans[n];
    //ans will store all adjacent nodes corresponding on index
    for(int i=0 ;i<m;i++){
        int u =edges[i][0];
        int v =edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int>> adj(n);
    for(int i =0;i<n;i++){
        adj[i].push_back(i);

        //enterning neighbours
        for(int j =0 ;j<ans[i].size();j++){
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;

}

//using adj matrix

const int MAXN = 100;

int graph[MAXN][MAXN];

void add_edge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;  // Add this line only if the graph is undirected
}

int main() {
    int n, m;
    cin >> n >> m;  // number of vertices and edges

    memset(graph, 0, sizeof(graph));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }
    // Do something with the graph
    return 0;
}
