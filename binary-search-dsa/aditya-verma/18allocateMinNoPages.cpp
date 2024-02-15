#include <bits/stdc++.h> 
using namespace std;

bool check(int A[], int N, int days, int Pages){
    int curr=0, d=1;
    for(int i=0;i<N;i++){
        curr += A[i];
        if(curr>Pages){
            curr=A[i];
            d++;
            if(d>days) return false;
        }
    }
    return true;
}

int findPages(int A[], int N, int M){

    if(M>N) return -1;
    int mx=0, mn=INT_MIN;
    for(int i=0;i<N;i++){
        mn = max(mn,A[i]);
        mx += A[i];
    }

    while(mn < mx){
        int mid= mn + (mx-mn)/2;
        if(check(A,N,M,mid)) mx=mid;
        else mn=mid+1;
    }
    return mn;
}
