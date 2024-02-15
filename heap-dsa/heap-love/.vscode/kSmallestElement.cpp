#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:

    int kthSmallest(int arr[],int l,int r, int k){
        priority_queue<int>pq;
        priority_queue <int,vector<int>,greater<int>> minheap;

        //step1
        for(int i =0;i<k;i++) pq.push(arr[i]);

        // step 2
        for(int i =k;i<=r;i++){
            if(arr[i]<pq.top()){
                pq.pop();
                pq.push(arr[i]);

            }
        }

        // ans = pq.top()
        int ans = pq.top();
        return ans;
    }

};