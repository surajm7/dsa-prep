#include <bits/stdc++.h> 
using namespace std;

int mx=INT_MIN, mn=INT_MAX;
	
void binarySearch(int s, int e, int v[], int toFind, bool leftBias){

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

int count(int arr[], int n, int x) {
  
  binarySearch(0,n-1,arr,x,true);
  binarySearch(0,n-1,arr,x,false);
  if(mn == INT_MAX) mn=-1;
  if(mx == INT_MIN) mx=-1;

  if(mn==-1) return 0;
  return mx-mn+1;
}
