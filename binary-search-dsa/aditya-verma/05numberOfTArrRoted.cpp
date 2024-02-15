#include <bits/stdc++.h> 
using namespace std;

int findKRotation(int arr[], int n) {
	    
    int s=0,e=n-1;
    if(arr[s]<=arr[e]) return 0;

    while(s<e){
        int m=s+(e-s)/2;
        if(arr[m]>arr[s]) s=m;
        else e=m;
    }

    return s+1;
}
