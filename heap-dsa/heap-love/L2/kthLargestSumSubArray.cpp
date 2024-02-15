#include <bits/stdc++.h> 
using namespace std;

int getKthLargest(vector<int>&arr , int k){
    priority_queue<int, vector<int>,greater<int>>mini;

    int n=arr.size();
    for(int i =0;i<n;i++){
        int sum=0;
        for(int j =i;j<n;j++){
            sum+=arr[j];
            if(mini.size()<k){
                mini.push(sum);
            }else{
                if(sum>mini.top()){
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    return mini.top();
}

int getKthLargest(vector<int>&arr , int k){
    vector<int> sumStore;
    int n =arr.size();
//O(N^2LOGN) , O(N^2)
    for(int i=0 ;i<n;i++){
        int sum=0;
        for(int j=1 ;j<n;j++){
            sum+=arr[j];
            sumStore.push_back(sum);
        }
    }
    sort(sumStore.begin(),sumStore.end());
    return sumStore[sumStore.size()-k];
}


