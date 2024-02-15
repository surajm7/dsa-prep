#include <bits/stdc++.h> 
using namespace std;


int mn=INT_MAX, mx=INT_MIN;

void binarySearch(int s, int e, vector<int> &v, int toFind, bool leftBias){

    if(s>e) return;

    int m=(s+e)/2;
    if(v[m]>toFind) binarySearch(s,m-1,v,toFind,leftBias);
    else if(v[m]<toFind) binarySearch(m+1,e,v,toFind,leftBias);
    else
        if(leftBias){
            mn=min(mn,m);
            binarySearch(s,m-1,v,toFind,leftBias);
        }else{
            mx=max(mx,m);
            binarySearch(m+1,e,v,toFind,leftBias);
        }
}

vector<int> searchRange(vector<int>& nums, int target) {

    binarySearch(0,nums.size()-1,nums,target,true);
    binarySearch(0,nums.size()-1,nums,target,false);
    if(mn == INT_MAX) mn=-1;
    if(mx == INT_MIN) mx=-1;
    return {mn,mx};
}
