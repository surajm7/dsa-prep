#include <bits/stdc++.h> 
using namespace std;

int findFloor(vector<long long> v, long long n, long long x){
    long long s=0,e=n-1,ans=-1;

    while(s<=e){
        int m = s+(e-s)/2;
        if(v[m]==x) return m;
        if(v[m]>x) e=m-1;
        else{
            if(ans==-1) ans=m;
            else if(v[m]>v[ans]) ans=m;
            s=m+1;
        }
    }

    return ans;
}
