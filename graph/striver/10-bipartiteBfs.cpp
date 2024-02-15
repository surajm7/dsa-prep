#include <bits/stdc++.h> 
using namespace std;

class Solution{
    private:
    bool check(int start , int V ,vector<int>adj[],int color[]){
        queue<int>q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto it : adj[node]){
                //if the adjacet node is yet not coloed
               //you will give the opposite color of the node
                if(color[it]== -1){
                    color[it]=!color[node];
                    q.push(it);
                }
                //is the adjacent guy having the same color
                //someone did color it on some othe path
                else if(color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(int V , vector<int>adj[]){
        int color[V];
        for(int i =0;i<V;i++) color[i]=-1;
        for(int i =0;i<V;i++){
            if(color[i]==-1){
                if(check(i,V,adj,color)==false){
                    return false;
                }
            }
        }
        return true;
    }

};