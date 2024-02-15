#include <bits/stdc++.h>
 using namespace std;

class Solution{
    public:
    int firstRepeating(int arr[], int n){
        unordered_map<int,int>umap;
        for(int i=0;i<n;i++){
            umap[arr[i]]++;
        }

        for(int i=0;i<n;i++){
            int key=arr[i];
            auto temp=umap.find(key);
            int val=temp->second;
            if(val>1) return i+1;
        }
        return -1;
    }
};