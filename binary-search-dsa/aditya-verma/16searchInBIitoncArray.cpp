#include <bits/stdc++.h> 
using namespace std;

int peak(vector<int>& arr) {
    int s=0, e=arr.size()-1;
      while(s<e){
        int m = s+(e-s)/2;
        if(m and arr[m] < arr[m-1]) e=m-1;
        else if(m<arr.size()-1 and arr[m] < arr[m+1]) s=m+1;
        else if(m==0){
            if(arr[0]>arr[1]){
                return 0;
            }else return 1;
        }else if(m==e){
            if(arr[e]>arr[e-1]){
                return e;
            }else{
                return e-1;
            }
        }
        else return m;
    }
    return s;
}

int bs(vector<int> &v, int s, int e, int x, bool dir){
    
    while(s<e){
        int m = s+(e-s)/2;
        if(v[m]==x) return m;
        if(v[m]>x)
            if(dir) e=m-1;
            else s=m+1;
        else
            if(dir) s=m+1;
            else e=m-1;
    }
    if(v[s] == x) return s;
    return -1;
}

int Solution::solve(vector<int> &A, int B) {
    int s=0,m,e=A.size()-1;

    m=peak(A);
    int i = bs(A,s,m-1,B,true);

    if(i != -1) return i;
    return bs(A,m,e,B,false);
}
